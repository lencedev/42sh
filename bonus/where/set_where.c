/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** set_where.c
*/

#include "file.h"

extern const exec_cmd_t set[NB_BUILT_IN];

static char *get_alias(buff_t *buff)
{
    list_t *alias_list = NULL;
    char *str = NULL;

    if (check_list_name(buff->list_alias, buff->tab[1])) {
        alias_list = find_env_list(buff->list_alias, buff->tab[1]);
        str = my_strdup(alias_list->value);
        return str;
    }
    return NULL;
}

static void is_aliased(buff_t *buff)
{
    if (check_list_name(buff->list_alias, buff->tab[1]))
        printf("%s is aliased to %s\n", buff->tab[1], get_alias(buff));
}

static int where_error(buff_t *buff)
{
    if (check_nb_args(buff->tab, 1) == 0) {
        printf("where: Too few arguments.\n");
        buff->value = 1;
        return 1;
    }
    return 0;
}

int exec_where(buff_t *buff)
{
    int i = 0;

    refresh_path(buff);
    if (where_error(buff))
        return buff->value;
    for (int i = 0; i != NB_BUILT_IN; i++)
        if (my_strcmp(buff->tab[1], my_strdup(set[i].name)) == 0)
            printf("%s is a shell built-in\n", buff->tab[1]);
        is_aliased(buff);
    for (; i < buff->path.nb_folders; i++)
        if (access(my_strcat(buff->path.parsed[i], buff->tab[1]), X_OK) == 0)
            printf("%s%s\n", buff->path.parsed[i], buff->tab[1]);
    if (i >= buff->path.nb_folders)
        return 0;
    return 1;
}
