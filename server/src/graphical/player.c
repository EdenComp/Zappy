/*
** EPITECH PROJECT, 2023
** server
** File description:
** team_name_answers.c
*/

#include "constants.h"
#include "graphical.h"
#include "util.h"

void plv_handler(server_t *server, client_t *client, char *line)
{
    (void) line;
    int player_nbr = 0; // getID(client->fd)
    int level = 0; // client->player->info->level

    append_buffer(client->buffer, "%s %i %i%s", GRAPHICAL_PLAYER_LEVEL, \
        player_nbr, level, LINE_BREAK);
}
