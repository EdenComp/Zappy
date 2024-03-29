/*
** EPITECH PROJECT, 2023
** server
** File description:
** map.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>

#include "buffer.h"
#include "constants.h"
#include "server.h"
#include "tasks.h"
#include "types.h"
#include "util.h"

void init_tick(server_t *server, long frequence)
{
    long micros = MICROS_PER_SEC / frequence;
    server->zappy->tick->freq = frequence;

    server->zappy->tick->tick_delay.tv_sec = micros / MICROS_PER_SEC;
    server->zappy->tick->tick_delay.tv_usec = micros % MICROS_PER_SEC;
}

void start_game(server_t *server)
{
    gettimeofday(&server->zappy->tick->game_start, NULL);
    gettimeofday(&server->zappy->tick->last_tick, NULL);
    debug(server, "Game started");
}

void refresh_timeout(server_t *server)
{
    struct timeval now;
    struct timeval elapsed;

    gettimeofday(&now, NULL);
    get_elapsed_time(&server->zappy->tick->last_tick, &now, &elapsed);
    get_elapsed_time(&elapsed, &server->zappy->tick->tick_delay, \
        &server->data->timeout);
}

bool tick(server_t *server)
{
    if (!server->zappy->paused) {
        server->zappy->tick->tick_nb += 1;
        execute_tasks(server);
    }
    gettimeofday(&server->zappy->tick->last_tick, NULL);
    return false;
}
