/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** execute_exe
*/

#include "file.h"

int check_slash(char *str)
{
    int nb = my_strlen(str);
    int i = 0;
    for (; str[i] != '/' && str[i] != '\0'; i++);
    return (nb != i) ? 1 : 0;
}

void refresh_path(buff_t *buff)
{
    list_t *list = buff->list_env;
    list_t *path = find_env_list(list, "PATH");

    if (check_list_name(list, "PATH")) {
        buff->path.nb_folders = count_parse(path->value, ':');
        buff->path.parsed = parsing_path(path->value);
    } else {
        buff->path.parsed = NULL;
        buff->path.nb_folders = 0;
    }
}

char *find_cmd(buff_t *buff)
{
    refresh_path(buff);

    if (!buff->path.parsed)
        return buff->tab[0];
    for (int i = 0; i < buff->path.nb_folders; i++)
        if (access(my_strcat(buff->path.parsed[i], buff->tab[0]), X_OK) == 0) {
            return my_strcat(buff->path.parsed[i], buff->tab[0]);
    }
    return buff->tab[0];
}
