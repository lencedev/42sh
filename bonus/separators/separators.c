/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** separators
*/

#include "file.h"

int or_separator_manager(buff_t *buff, int fd[2])
{
    int nb_or = count_multi_parses(buff->cmd.cmd, "||");
    char **parsed = get_array_custom(buff->cmd.cmd, "||");

    if (nb_or < 2) {
        if (checker(buff->cmd.cmd))
            return buff->value = pipes_manager(buff, fd);
        else
            return buff->value;
    }
    for (; *parsed; *parsed++) {
        buff->cmd.cmd = my_strdup(*parsed);
        if (*buff->cmd.cmd)
            pipes_manager(buff, fd);
        if (buff->value == 0)
            return 0;
    }
    return buff->value;
}

int and_separator_manager(buff_t *buff, int fd[2])
{
    int nb_and = count_multi_parses(buff->cmd.cmd, "&&");
    char **parsed = get_array_custom(buff->cmd.cmd, "&&");
    buff->value = 0;

    if (nb_and < 2)
        if (checker(buff->cmd.cmd))
            return buff->value = or_separator_manager(buff, fd);
        else
            return buff->value;
    if (check_error(buff, parsed, nb_and))
        return display_or_error();
    for (; *parsed; *parsed++) {
        buff->cmd.cmd = my_strdup(*parsed);
        if (*buff->cmd.cmd)
            buff->value = or_separator_manager(buff, fd);
        if (buff->value != 0)
            return 1;
    }
    return buff->value;
}

int coma_separator_manager(buff_t *buff)
{
    char **parsed;
    int fd[2] = {STDIN_FILENO, STDOUT_FILENO};
    buff->cmd.cmd = my_strdup(buff->line);

    if (!(count_parse(buff->cmd.cmd, ';') > 1))
        if (checker(buff->cmd.cmd))
            return buff->value = and_separator_manager(buff, fd);
        else
            return buff->value;
    parsed = parsing_line(buff->cmd.cmd, ';');
    for (; *parsed; *parsed++) {
        buff->cmd.cmd = my_strdup(*parsed);
        if (*buff->cmd.cmd)
            buff->value = and_separator_manager(buff, fd);
    }
    return buff->value;
}
