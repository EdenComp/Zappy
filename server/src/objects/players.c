/*
** EPITECH PROJECT, 2023
** server
** File description:
** players.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>

#include "player.h"
#include "types.h"

static bool init_command_queue(player_t *new)
{
    new->commands = malloc(sizeof(command_queue_t));
    if (new->commands == NULL) {
        perror("malloc failed");
        return false;
    }
    STAILQ_INIT(new->commands);
    return true;
}

player_t *new_player(void)
{
    static size_t next_id = 0;
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL) {
        perror("malloc failed");
        return NULL;
    }
    new->id = next_id++;
    new->level = 1;
    new->team = NULL;
    new->pos = NULL;
    new->dead = false;
    new->direction = rand() % 4;
    memset(new->inventory, 0, sizeof(new->inventory));
    new->inventory[FOOD] = FOOD_DEFAULT;
    if (!init_command_queue(new)) {
        free(new);
        return NULL;
    }
    return new;
}

void free_player(player_t *player)
{
    command_t *command = NULL;

    if (player->team != NULL) {
        player->team->slots++;
        SLIST_REMOVE(player->team->players, player, player, next_team);
    }
    if (player->pos != NULL) {
        SLIST_REMOVE(&player->pos->players, player, player, next_tile);
    }
    while (!STAILQ_EMPTY(player->commands)) {
        command = STAILQ_FIRST(player->commands);
        STAILQ_REMOVE_HEAD(player->commands, next);
        free(command->command);
        free(command);
    }
    free(player->commands);
    free(player);
}
