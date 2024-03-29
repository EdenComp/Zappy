/*
** EPITECH PROJECT, 2023
** MyTeams
** File description:
** server.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "server.h"
#include "types.h"

static void display_help_server(char const *binary)
{
    printf("USAGE: %s -p port -x width -y height", binary);
    printf(" -n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\tis the reciprocal of time unit for \n");
    printf("execution of actions\nOPTIONAL FLAGS:\n");
    printf("\t--debug\t\tenables debug mode\n");
    printf("\t--immortal\tdisables food consumption\n");
    printf("\t--seed seed\talters the randomness of the game\n");
}

static bool is_help(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-help") == 0) {
            return true;
        }
    }
    return false;
}

static void destroy_options(options_t *options)
{
    if (options->names != NULL) {
        free(options->names);
    }
}

int zappy_server(int argc, char const *argv[])
{
    bool res = false;
    options_t options;

    memset(&options, 0, sizeof(options_t));
    if (is_help(argc, argv)) {
        display_help_server(argv[0]);
        return SUCCESS;
    }
    if (!check_arguments(argc, argv, &options)) {
        return FAILURE;
    }
    res = start_server(&options);
    destroy_options(&options);
    return res ? SUCCESS : FAILURE;
}
