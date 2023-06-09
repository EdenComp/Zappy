/*
** EPITECH PROJECT, 2023
** server
** File description:
** player.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>

#include "constants.h"
#include "player.h"
#include "types.h"
#include "util.h"

static void handle_player_command(server_t *server, client_t *client, \
    char *line)
{
    bool accept = false;

    for (size_t i = 0; i < PLAYER_COMMANDS_COUNT; i++) {
        if (PLAYER_COMMANDS[i].args) {
            accept = strncmp(line, PLAYER_COMMANDS[i].command, \
                strlen(PLAYER_COMMANDS[i].command)) == 0;
        } else {
            accept = strcmp(line, PLAYER_COMMANDS[i].command) == 0;
        }
        if (accept) {
            PLAYER_COMMANDS[i].function(server, client, line);
            return;
        }
    }
    append_buffer(client->buffer_out, "%s%s", PLAYER_UNKNOWN, LINE_BREAK);
    flush_command(server, client);
}

static bool can_accept_command(client_t *client)
{
    size_t len = 0;
    command_t *command = NULL;

    if (!client->player->action_task->running) {
        return true;
    }
    STAILQ_FOREACH(command, client->player->commands, next) {
        len++;
    }
    return len < MAX_ACTIONS - 1;
}

void register_command(server_t *server, client_t *client, char *line)
{
    command_t *command = NULL;

    if (!can_accept_command(client))
        return;
    if (!client->player->action_task->running) {
        handle_player_command(server, client, line);
        return;
    }
    command = malloc(sizeof(command_t));
    if (command == NULL) {
        perror("malloc failed");
        return;
    }
    command->command = strdup(line);
    if (command->command == NULL) {
        perror("strdup failed");
        free(command);
        return;
    }
    STAILQ_INSERT_TAIL(client->player->commands, command, next);
}

void flush_command(server_t *server, client_t *client)
{
    command_t *command = STAILQ_FIRST(client->player->commands);

    if (command == NULL) {
        return;
    }
    STAILQ_REMOVE_HEAD(client->player->commands, next);
    handle_player_command(server, client, command->command);
    free(command->command);
    free(command);
}
