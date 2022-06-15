/*
** EPITECH PROJECT, 2022
** 42SH
** File description:
** is_num
*/

#include "file.h"

int is_num(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= '0' || str[i] <= '9')
            return 0;
    }
    return 1;
}
