/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** parse_list
*/

#include "file.h"

int check_list_name(list_t *env, const char *name)
{
    for (; env; env = env->next) {
        if (my_strncmp(env->name, name, my_strlen(name)) == 0)
            return 1;
    }
    return 0;
}

void edit_list_name(list_t **env, const char *str, const char *name)
{
    list_t *list = find_env_list(*env, str);

    list->name = my_strdup(name);
}

void edit_list_value(list_t **env, const char *str, const char *value)
{
    list_t *list = find_env_list(*env, str);

    list->value = my_strdup(value);
}

list_t *find_env_list(list_t *env, const char *str)
{
    for (; env && my_strncmp(env->name, str, my_strlen(str)); env = env->next);
    return env;
}
