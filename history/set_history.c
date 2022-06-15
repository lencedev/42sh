/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** set_history
*/

#include "file.h"

void node_time_push_front(listoric_t **list, char *str)
{
    listoric_t *new = malloc(sizeof(listoric_t));
    new->time = str;
    new->next = (*list);
    *list = new;
}

void node_time_push_back(listoric_t **list, char *str)
{
    listoric_t *new = malloc(sizeof(listoric_t));
    new->time = str;
    new->next = NULL;
    listoric_t *back = NULL;

    if (*list == NULL)
        *list = new;
    else {
        back = *list;
        while (back->next != NULL)
            back = back->next;
        back->next = new;
    }
}

void node_cmd_push_front(listoric_t **list, char *str)
{
    listoric_t *new = malloc(sizeof(listoric_t));
    new->cmd = str;
    new->next = (*list);
    *list = new;
}

void node_cmd_push_back(listoric_t **list, char *str)
{
    listoric_t *new = malloc(sizeof(listoric_t));
    new->cmd = str;
    new->next = NULL;
    listoric_t *back = NULL;

    if (*list == NULL)
        *list = new;
    else {
        back = *list;
        while (back->next != NULL)
            back = back->next;
        back->next = new;
    }
}
