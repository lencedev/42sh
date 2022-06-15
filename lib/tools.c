/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** tools
*/

#include "file.h"

char *my_strndup(const char *src, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));
    int i = 0;

    if (dest == NULL)
        return NULL;
    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup(const char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (dest == NULL)
        return NULL;
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    while (*str1 && *str2 && --n && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *my_strcat(char *str1, char *str2)
{
    char *dest = malloc(my_strlen(str1) + my_strlen(str2) + 1);
    int a = 0;

    for (; *str1; str1++)
        dest[a++] = *str1;
    for (; *str2; str2++)
        dest[a++] = *str2;
    dest[a] = 0;
    return dest;
}
