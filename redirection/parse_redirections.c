/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-owen1.bolling
** File description:
** parse_redirections
*/

#include "file.h"

char *parse_output(char **buff)
{
    char **parsed = get_array(buff[1]);
    char *output = parsed[0];

    return output;
}

char *parse_cmd(char **buff)
{
    char **parse = get_array(my_strdup(buff[1]));
    char *output = parse[0];
    char *start = my_strndup(buff[0], my_strlen(buff[0]) - 1);
    char *end = my_strdup(buff[1] + my_strlen(output) +1);
    char *cmd = my_strcat(start, end);
    return cmd;
}

void split_line(char ***tab, char *line, char obj)
{
    int y = 0;
    int j = 0;
    for (int i = 0; line[i]; i++) {
        if (line[i] == obj) {
            (*tab)[y][j] = '\0';
            j = 0;
            y += 1;
            continue;
        }
        (*tab)[y][j] = line[i];
        j += 1;
    }
    (*tab)[y][j] = '\0';
    (*tab)[y + 1] = '\0';
}

char **parsing_line(char *line, char obj)
{
    int nb = count_parse(line, obj) + 1;
    char **tab = malloc(nb * sizeof(char *));
    for (int n = 0; n < nb; n++)
        tab[n] = malloc(sizeof(char) * my_strlen(line));
    split_line(&tab, line, obj);
    return tab;
}
