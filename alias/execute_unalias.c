/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** execute_unalias
*/

#include "file.h"

int msg_unset_list(buff_t *buff)
{
    write(buff->cmd.fd[1], buff->tab[0], my_strlen(buff->tab[0]));
    write(buff->cmd.fd[1], ": Too few arguments.\n", 21);
    return 1;
}

int unset_list(list_t **env, const char *s)
{
    list_t *lst = *env;
    list_t *tmp = NULL;

    while (lst->next && my_strncmp(lst->next->name, s, my_strlen(s)))
        lst = lst->next;
    tmp = lst->next;
    if (lst && lst->next && lst->next->next)
        lst->next = lst->next->next;
    else
        lst->next = NULL;
    free(tmp);
    return 0;
}

int unset_all_alias(buff_t *buff)
{
    for (; buff->list_alias; buff->list_alias = buff->list_alias->next)
        unset_env(&buff->list_alias, buff->list_alias->name);
    return 0;
}

int exec_unalias(buff_t *buff)
{
    if (buff->tab[1] == NULL)
        return msg_unset_list(buff);
    if (my_strcmp(buff->tab[1], "*") == 0)
        return unset_all_alias(buff);
    return unset_list(&buff->list_alias, buff->tab[1]);
}
