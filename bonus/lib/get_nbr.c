/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** get_nbr
*/

#include "file.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int isneg = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            isneg = isneg * -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
        nb *= 10;
        nb += str[i] - '0';
        i++;
    }
    return (nb * isneg);
}
