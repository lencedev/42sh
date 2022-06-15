/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** parsing_tools
*/

#include "file.h"

char **get_array(char *line)
{
    int nb_line = count_words(my_strdup(line));
    char **tab = malloc(sizeof(char *) * (nb_line + 1));
    char *s = " \t";
    int j = 0;

    for (int i = 0; i < nb_line; i++)
        tab[i] = malloc(sizeof(my_strlen(line)));
    for (char *token = strtok(line, s); token; token = strtok(NULL, s))
        tab[j++] = token;
    tab[j] = '\0';
    return tab;
}

char *parse_env_path(char **env, char *str, int size)
{
    int i = 0;
    for (; *env && my_strncmp(*env, str, my_strlen(str)) != 0; env += 1);
    char *path = malloc(sizeof(char) * (my_strlen(*env) + 1));
    for (; env[0][size]; size++) {
        path[i] = env[0][size];
        i++;
    }
    path[i] = '\0';
    return path;
}

int count_parse(char *str, char obj)
{
    int nb = 0;
    for (; *str; *str++)
        if (*str == obj)
            nb++;
    return nb + 1;
}

int count_words(char *line)
{
    char *token;
    char *s = " \t";
    int nb = 0;
    char *line_smurf = line;

    token = strtok(line_smurf, s);

    while (token != NULL) {
        nb++;
        token = strtok(NULL, s);
    }
    return nb;
}

char *parse_pwd(char *env, char *str, int size)
{
    int i = 0;
    for (; *env && my_strncmp(env, str, my_strlen(str)) != 0; *env += 1);
    char *path = malloc(sizeof(char) * (my_strlen(env) + 1));
    for (; env[size]; size++) {
        path[i] = env[size];
        i++;
    }
    path[i] = '\0';
    return path;
}
