/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** unset_var
*/

#include "file.h"

int unset_all_var(buff_t *buff)
{
    for (; buff->list_var; buff->list_var = buff->list_var->next)
        unset_list(&buff->list_var, buff->list_var->name);
    return 0;
}

int exec_unset(buff_t *buff)
{
    if (buff->tab[1] == NULL)
        return msg_unset_list(buff);
    if (my_strcmp(buff->tab[1], "*") == 0)
        return unset_all_var(buff);
    return unset_list(&buff->list_var, buff->tab[1]);
}
