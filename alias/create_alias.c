/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** create_alias
*/

#include "file.h"

int edit_alias(buff_t *buff)
{
    if (buff->tab[2]) {
        edit_list_value(&buff->list_alias, buff->tab[1], buff->tab[2]);
        return 1;
    }
    edit_list_value(&buff->list_alias, buff->tab[1], "");
    return 0;
}

int create_alias(buff_t *buff, char *arg)
{
    if (buff->tab[2]) {
        create_node_at_back(&buff->list_alias, my_strcat(arg, buff->tab[2]));
        return 1;
    }
    create_node_at_back(&buff->list_alias, arg);
    return 0;
}

int create_or_edit_alias(buff_t *buff, char *arg)
{
    if (check_list_name(buff->list_alias, buff->tab[1]))
        return edit_alias(buff);
    return create_alias(buff, arg);
}
