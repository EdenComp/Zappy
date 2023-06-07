/*
** EPITECH PROJECT, 2023
** server
** File description:
** scheduler.c
*/

#include <stdbool.h>
#include <stddef.h>

#include "server.h"
#include "types.h"

static void execute_task(server_t *server, task_t *task)
{
    task->current--;
    if (task->current > 0) {
        return;
    }
    task->callback(server, task->client);
    task->current = task->delay;
    if (task->executions == -1) {
        return;
    }
    task->executions--;
    if (task->executions == 0) {
        task->running = false;
    }
}

void execute_tasks(server_t *server)
{
    task_t *node = server->tasks->slh_first;
    task_t *tmp = NULL;

    while (node != NULL) {
        tmp = node->next.sle_next;
        if (node->running) {
            execute_task(server, node);
        }
        node = tmp;
    }
}