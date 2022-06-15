/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execute_alias
*/

#include "file.h"

int print_alias(buff_t buff)
{
    for (; buff.list_alias; buff.list_alias = buff.list_alias->next) {
        write(buff.cmd.fd[1], buff.list_alias->name,
        my_strlen(buff.list_alias->name));
        write(buff.cmd.fd[1], "\t", 1);
        write(buff.cmd.fd[1], buff.list_alias->value,
        my_strlen(buff.list_alias->value));
        write(buff.cmd.fd[1], "\n", 1);
    }
    return 0;
}

void find_alias(buff_t *buff)
{
    list_t *alias_list = NULL;

    while (check_list_name(buff->list_alias, buff->tab[0])) {
        alias_list = find_env_list(buff->list_alias, buff->tab[0]);
        buff->tab[0] = my_strdup(alias_list->value);
    }
}

int exec_alias(buff_t *buff)
{
    char *arg = NULL;

    if (!buff->tab[1])
        return print_alias(*buff);
    arg = my_strcat(buff->tab[1], "=");
    if (check_setenv_name(buff->tab[1]))
        return create_or_edit_alias(buff, arg);
    return buff->value = 1;
}
