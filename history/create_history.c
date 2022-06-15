/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** create_history_list
*/

#include "file.h"
// #include <stdio.h>
// #include <string.h>
// #include <time.h>
// #include <stdlib.h>

char *get_history_time(void)
{
    time_t _time = time(NULL);
    struct tm *history = localtime(&_time);
    char *buf = malloc(sizeof(char) * 7);
    int hour = history->tm_hour;
    int min = history->tm_min;

    if (hour < 10 && min < 10)
        buf = my_strcat(my_strcat(my_strcat("0", my_itoa(hour)),
        ":"), my_strcat("0", my_itoa(min)));
    if (hour < 10 && min >= 10)
        buf = my_strcat(my_strcat(my_strcat("0", my_itoa(hour)),
        ":"), my_itoa(min));
    if (hour >= 10 && min < 10)
        buf = my_strcat(my_strcat(my_itoa(hour), ":"),
        my_strcat("0", my_itoa(min)));
    else
        buf = my_strcat(my_strcat(my_itoa(hour), ":"), my_itoa(min));
    return buf;
}

listoric_t *create_history(buff_t *buff)
{
    listoric_t *list = malloc(sizeof(listoric_t));

    list->nb = 0;
    list->time = get_history_time();
    list->cmd = buff->cmd.cmd;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void change_history_list(buff_t *buff)
{
    node_cmd_push_back(&buff->listoric, buff->line);
    node_time_push_back(&buff->listoric, get_history_time());
    buff->listoric->next = create_history(buff);
}

int print_history(buff_t *buf)
{
    for (int i = 1; buf->listoric; buf->listoric = buf->listoric->next, i++) {
        buf->listoric->nb = i;
        printf("     %d", buf->listoric->nb);
        printf("  %s", buf->listoric->time);
        printf("   %s\n", buf->listoric->cmd);
    }
    return 0;
}
