/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** set_var
*/

#include "file.h"

static void create_node_at_back_var(list_t **env, char *name, char *value)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *list = *env;

    node->name = my_strdup(name);
    node->value = my_strdup(value);
    node->next = NULL;
    if (list) {
        while (list->next)
            list = list->next;
        list->next = node;
    } else
        *env = node;
}

int edit_var(buff_t *buff, char *name, char *value)
{
    if (value) {
        edit_list_value(&buff->list_var, name, value);
        return 1;
    }
    edit_list_value(&buff->list_var, name, "");
    return 0;
}

int create_var(buff_t *buff, char *name, char *value)
{
    if (value) {
        create_node_at_back_var(&buff->list_var, name, value);
        return 1;
    }
    create_node_at_back_var(&buff->list_var, name, "");
    return 0;
}

int create_or_edit_var(buff_t *buff, char *name, char *value)
{
    if (check_list_name(buff->list_var, name))
        return edit_var(buff, name, value);
    return create_var(buff, name, value);
}
