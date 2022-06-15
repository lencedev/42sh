/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** unset_env
*/

#include "file.h"

int msg_unset_env(buff_t *buff)
{
    write(buff->cmd.fd[1], buff->tab[0], my_strlen(buff->tab[0]));
    write(buff->cmd.fd[1], ": Too few arguments.\n", 21);
    return 1;
}

int unset_env_all(buff_t *buff)
{
    for (; buff->list_env; buff->list_env = buff->list_env->next)
        unset_env(&buff->list_env, buff->list_env->name);
    return 0;
}

int unset_env(list_t **env, const char *s)
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

int exec_unsetenv(buff_t *buff)
{
    if (buff->tab[1] == NULL)
        return msg_unset_env(buff);
    if (my_strcmp(buff->tab[1], "*") == 0)
        return unset_env_all(buff);
    return unset_list(&buff->list_env, buff->tab[1]);
}
