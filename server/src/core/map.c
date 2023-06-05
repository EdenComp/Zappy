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
#include <sys/queue.h>

#include "server.h"
#include "types.h"

static void init_tiles(server_t *server)
{
    for (int i = 0; i < server->options->height; i++) {
        for (int j = 0; j < server->options->width; j++) {
            server->zappy->map[i][j].x = j;
            server->zappy->map[i][j].y = i;
            SLIST_INIT(&server->zappy->map[i][j].players);
        }
    }
}

void free_map(server_t *server)
{
    if (server->zappy->map == NULL)
        return;
    for (int i = 0; i < server->options->height; i++) {
        free(server->zappy->map[i]);
    }
    free(server->zappy->map);
}

bool init_map(server_t *server)
{
    size_t array_size = sizeof(tile_t) * (server->options->height);

    server->zappy->map = malloc(sizeof(tile_t *) * (server->options->height));
    if (server->zappy->map == NULL) {
        perror("malloc failed");
        return false;
    }
    for (int i = 0; i < server->options->height; i++) {
        server->zappy->map[i] = malloc(array_size);
        if (server->zappy->map[i] == NULL) {
            perror("malloc failed");
            free_map(server);
            return false;
        }
        memset(server->zappy->map[i], 0, array_size);
    }
    init_tiles(server);
    return true;
}
