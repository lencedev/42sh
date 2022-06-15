/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** tools
*/

#ifndef TOOLS_H_
    #define TOOLS_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(const char *line);
char *my_strcat(char *str1, char *str2);
char *my_strdup(const char *src);
int my_strncmp(const char *str1, const char *str2, size_t n);
char *my_strndup(const char *src, int n);
int my_getnbr(char const *str);
int my_strcmp(const char *str1, const char *str2);
char *my_itoa(int nb);

#endif /* !TOOLS_H_ */
