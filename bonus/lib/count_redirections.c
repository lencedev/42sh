/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-owen1.bolling
** File description:
** count_redirections
*/

#include "file.h"

int count_words_custom(char *line, char *obj)
{
    char *token = NULL;
    int nb = 0;
    char *line_smurf = my_strdup(line);
    char *obj_smurf = my_strdup(obj);

    token = strtok(line_smurf, obj_smurf);

    while (token != NULL) {
        nb++;
        token = strtok(NULL, obj_smurf);
    }
    return nb;
}

char **get_array_custom(char *str, char *obj)
{
    char *line = my_strdup(str);
    int nb_line = count_words_custom(my_strdup(line), obj);
    char **tab = malloc(sizeof(char *) * (nb_line + 1));
    int j = 0;

    for (int i = 0; i < nb_line; i++)
        tab[i] = malloc(sizeof(my_strlen(line)));

    for (char *token = strtok(line, obj); token; token = strtok(NULL, obj))
        tab[j++] = token;
    tab[j] = '\0';
    return tab;
}

int count_multi_parses(char *str, char *obj)
{
    int nb = 0;
    for (int i = 0; str[i] && str[i + 1]; i++)
        if (str[i] == obj[0] && (str[i + 1] == obj[1]))
            nb++;
    return nb + 1;
}
