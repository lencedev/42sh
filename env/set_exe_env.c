/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** set_exe_env
*/

#include "file.h"
#include "error.h"

int create_env(buff_t *buff, char *arg)
{
    if (buff->tab[2]) {
        create_node_at_back(&buff->list_env, my_strcat(arg, buff->tab[2]));
        return 1;
    }
    create_node_at_back(&buff->list_env, arg);
    return 0;
}

int edit_env(buff_t *buff)
{
    if (buff->tab[2]) {
        edit_list_value(&buff->list_env, buff->tab[1], buff->tab[2]);
        return 1;
    }
    edit_list_value(&buff->list_env, buff->tab[1], "");
    return 0;
}

int create_or_edit_env(buff_t *buff, char *arg)
{
    if (check_list_name(buff->list_env, buff->tab[1]))
        return edit_env(buff);
    return create_env(buff, arg);
}

int exec_setenv(buff_t *buff)
{
    char *arg = NULL;

    if (!buff->tab[1])
        return print_env(*buff);
    arg = my_strcat(buff->tab[1], "=");
    if (check_nb_args(buff->tab, 3))
        return setenv_nb_args(buff);
    if (check_setenv_name(buff->tab[1]))
        return create_or_edit_env(buff, arg);
    return buff->value = 1;
}

int exec_env(buff_t *buff)
{
    if (my_strncmp(*buff->tab, "env", 4) == 0)
        return print_env(*buff);
    if (my_strncmp(*buff->tab, "setenv", 7) == 0)
        return exec_setenv(buff);
    if (my_strncmp(*buff->tab, "unsetenv", 9) == 0)
        return exec_unsetenv(buff);
    return 1;
}
