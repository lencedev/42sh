/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** set_env
*/

#include "file.h"

int print_env(buff_t buff)
{
    for (; buff.list_env; buff.list_env = buff.list_env->next) {
        write(buff.cmd.fd[1], buff.list_env->name,
        my_strlen(buff.list_env->name));
        write(buff.cmd.fd[1], "=", 1);
        write(buff.cmd.fd[1], buff.list_env->value,
        my_strlen(buff.list_env->value));
        write(buff.cmd.fd[1], "\n", 1);
    }
    return 0;
}

int len_until_char(const char *str, char c)
{
    int i = 0;

    while (str[i] != c)
        i++;
    return i;
}

void create_node_at_back(list_t **env, const char *str)
{
    list_t *node = malloc(sizeof(list_t));
    int len = len_until_char(str, '=');
    list_t *list = *env;

    node->name = my_strndup(str, len);
    node->value = my_strdup(str + (len + 1));
    node->next = NULL;
    if (list) {
        while (list->next)
            list = list->next;
        list->next = node;
    } else
        *env = node;
}

void init_env(buff_t *buff)
{
    list_t *env = NULL;

    for (int i = 0; buff->env[i]; i++) {
        create_node_at_back(&env, buff->env[i]);
    }
    buff->list_env = env;
}
