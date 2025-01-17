/*
** EPITECH PROJECT, 2023
** server
** File description:
** map.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/queue.h>

#include "constants.h"
#include "resources.h"
#include "server.h"
#include "tasks.h"
#include "types.h"
#include "util.h"

static bool init_map_utils(server_t *server)
{
    size_t area = server->options->width * server->options->height;
    double *densities = malloc(sizeof(double) * area);
    tile_t **empty = malloc(sizeof(tile_t *) * area);
    tile_t **updated = malloc(sizeof(tile_t *) * area);

    if (densities == NULL || empty == NULL || updated == NULL) {
        perror("malloc failed");
        return false;
    }
    server->zappy->densities = densities;
    server->zappy->empty = empty;
    server->zappy->updated = updated;
    return true;
}

static bool populate_map(server_t *server)
{
    double density = 0.0;
    bool *arg = malloc(sizeof(bool));
    task_t *task = register_task(server, NULL, &refill_callback);

    if (task == NULL || arg == NULL) {
        free_all(2, task, arg);
        return false;
    }
    *arg = true;
    for (size_t i = 0; i < RESOURCES_TYPES_QUANTITY; i++) {
        density = RESOURCES[i].density * \
            server->options->width * server->options->height;
        server->zappy->total[i] = MAX(1, density);
        server->zappy->current[i] = 0;
    }
    task->arg = arg;
    refill_callback(server, NULL, arg);
    schedule_task(task, server, REFILL_DELAY, -1);
    return true;
}

static void init_tiles(server_t *server)
{
    for (int i = 0; i < server->options->height; i++) {
        for (int j = 0; j < server->options->width; j++) {
            server->zappy->map[i][j].x = j;
            server->zappy->map[i][j].y = i;
            SLIST_INIT(&server->zappy->map[i][j].players);
            SLIST_INIT(&server->zappy->map[i][j].eggs);
        }
    }
}

void free_map(server_t *server)
{
    for (int i = 0; i < server->options->height; i++) {
        free(server->zappy->map[i]);
    }
    free(server->zappy->map);
}

bool init_map(server_t *server)
{
    size_t array_size = sizeof(tile_t) * (server->options->width);

    if (!init_map_utils(server))
        return false;
    server->zappy->map = malloc(sizeof(tile_t *) * (server->options->height));
    if (server->zappy->map == NULL) {
        perror("malloc failed");
        return false;
    }
    memset(server->zappy->map, 0, sizeof(tile_t *) * (server->options->height));
    for (int i = 0; i < server->options->height; i++) {
        server->zappy->map[i] = malloc(array_size);
        if (server->zappy->map[i] == NULL) {
            perror("malloc failed");
            return false;
        }
        memset(server->zappy->map[i], 0, array_size);
    }
    init_tiles(server);
    return populate_map(server);
}
