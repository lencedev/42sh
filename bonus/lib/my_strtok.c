/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** my_strtok
*/

#include "file.h"

int is_in(char *str, char ch)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == ch)
            return 1;
    return 0;
}

int split_quantity(char *str, char *separators)
{
    int i = 0;
    int qtt = 1;

    for (; str[i]; i++)
        if (is_in(separators, str[i]) &&
        (i != 0 && is_in(separators, str[i - 1]) == 0))
            qtt++;
    return qtt;
}

void fill_up_array(char **array, char *str, char *separators)
{
    int i = 0;
    int j = 0;
    int target = 0;

    for (; str[i]; i++) {
        if (is_in(separators, str[i]) && (i != 0 &&
        is_in(separators, str[i - 1]) == 0)) {
            array[target][j] = 0;
            target++;
            j = 0;
        } else if ((i == 0 && is_in(separators, str[i]) == 0) ||
        i != 0 && (is_in(separators, str[i - 1]) == 0 ||
        (is_in(separators, str[i - 1]) && is_in(separators, str[i]) == 0))) {
            array[target][j] = str[i];
            j++;
        }
    }
    array[target][j] = 0;
    array[target + 1] = NULL;
}

char **my_strtok(char *str, char *separators)
{
    char **array = NULL;
    int j = 0;
    int k = 0;

    if (str == NULL)
        return NULL;
    array = malloc(sizeof(char *) * (split_quantity(str, separators) + 1));
    for (int i = 0; str[i]; i++) {
        if (is_in(separators, str[i]) && (i != 0 &&
        is_in(separators, str[i - 1]) == 0)) {
            array[k] = malloc(sizeof(char) * (j + 1));
            j = 0;
            k++;
        } else
            j += (is_in(separators, str[i]) && (i == 0 ||
            is_in(separators, str[i - 1]))) ? 0 : 1;
    }
    array[k] = malloc(sizeof(char) * (j + 1));
    fill_up_array(array, str, separators);
    return array;
}
