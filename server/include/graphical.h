/*
** EPITECH PROJECT, 2023
** server
** File description:
** graphical.h
*/

#ifndef GRAPHICAL_H_
    #define GRAPHICAL_H_

    #define GRAPHICAL_COMMANDS_COUNT \
        (sizeof(GRAPHICAL_COMMANDS) / sizeof(graphical_command_t))

    #define GRAPHICAL_IDENTIFIER "GRAPHIC"

    #define GRAPHICAL_MAP_SIZE "msz"
    #define GRAPHICAL_TEAM_NAME "tna"
    #define GRAPHICAL_PLAYER_LEVEL "plv"
    #define GRAPHICAL_UNKNOWN "suc"

    #include "types.h"

void handle_graphical_command(server_t *server, client_t *client, char *line);

void msz_handler(server_t *server, client_t *client, char *line);
void tna_handler(server_t *server, client_t *client, char *line);
void plv_handler(server_t *server, client_t *client, char *line);

typedef void (graphical_handler_t) \
    (server_t *server, client_t *client, char *line);

typedef struct graphical_command {
    char const *command;
    graphical_handler_t *function;
} graphical_command_t;

static const graphical_command_t GRAPHICAL_COMMANDS[] = {
        { GRAPHICAL_MAP_SIZE, &msz_handler },
        { GRAPHICAL_TEAM_NAME, &tna_handler },
        { GRAPHICAL_PLAYER_LEVEL, &plv_handler },
};

#endif
