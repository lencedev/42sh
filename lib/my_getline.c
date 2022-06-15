/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** my_getline
*/

#include "file.h"

void exit_process(int value)
{
    if (isatty(0))
        write(1, "exit\n", 6);
    exit(value);
}

void my_getline(buff_t *buff)
{
    buff->len = getline(&buff->line, &buff->len, stdin);

    if (buff->len == -1)
        exit_process(buff->value);
    if (buff->len == 0) {
        buff->line = NULL;
        return;
    }
    else if (buff->line[buff->len - 1] != '\n')
        buff->line[buff->len] = '\0';
    else
        buff->line[buff->len - 1] = '\0';
}
