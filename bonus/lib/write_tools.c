/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** write_tools
*/

#include "file.h"

int my_strlen(const char *line)
{
    int i = 0;

    for (; line[i] != '\0'; i++);
    return i;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (; *str; str++)
        my_putchar(*str);
}
