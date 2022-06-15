/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** execute_var
*/

#include "file.h"

int print_var_error(buff_t buff, char *cmd)
{
    cmd = my_strdup(cmd + 1);
    write(buff.cmd.fd[1], cmd, my_strlen(cmd));
    write(buff.cmd.fd[1], ": Undefined variable.\n", 22);
    return 1;
}

int print_var(buff_t buff)
{
    for (; buff.list_var; buff.list_var = buff.list_var->next) {
        write(buff.cmd.fd[1], buff.list_var->name,
        my_strlen(buff.list_var->name));
        write(buff.cmd.fd[1], "\t", 1);
        write(buff.cmd.fd[1], buff.list_var->value,
        my_strlen(buff.list_var->value));
        write(buff.cmd.fd[1], "\n", 1);
    }
    return 0;
}

int check_var(buff_t *buff, int i)
{
    list_t *var_list = NULL;

    while (check_list_var_name(buff->list_var, buff->tab[i])) {
        var_list = find_var_list(buff->list_var, buff->tab[i]);
        buff->tab[i] = my_strdup(var_list->value);
    }
    if (buff->tab[i][0] == '$')
        return print_var_error(*buff, buff->tab[i]);
    return 0;
}

int find_var(buff_t *buff)
{
    char **cmd = buff->tab;
    int i = 0;
    int id = 0;

    for (; cmd[i]; i++)
        id = check_var(buff, i);
    if (id) {
        buff->value = 1;
        return 1;
    }
    return 0;
}

int exec_var(buff_t *buff)
{
    char *name = NULL;
    char *value = NULL;
    char *tmp = NULL;
    int len = 0;

    if (!buff->tab[1])
        return print_var(*buff);
    tmp = my_strdup(buff->tab[1]);
    len = len_until_char(tmp, '=');
    name = my_strndup(tmp, len);
    value = my_strdup(tmp + (len + 1));
    if (check_var_name(name))
        return create_or_edit_var(buff, name, value);
    return buff->value = 1;
}
