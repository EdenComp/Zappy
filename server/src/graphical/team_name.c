/*
** EPITECH PROJECT, 2023
** server
** File description:
** team_name_answers.c
*/

#include "constants.h"
#include "graphical.h"
#include "util.h"

void tna_handler(server_t *server, client_t *client, char *line)
{
    (void) line;
    for (size_t i = 0; server->options->names[i] != NULL; i++) {
        append_buffer(client->buffer, "%s %s%s", GRAPHICAL_TEAM_NAME, \
            server->options->names[i], LINE_BREAK);
    }
}
