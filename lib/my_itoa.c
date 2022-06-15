/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** my_itoa
*/

#include "tools.h"

int my_numlen(int nb)
{
    int count = 0;

    if (nb < 0)
        nb *= -1;
    while (nb != 0) {
        count++;
        nb /= 10;
    }
    return count;
}

char *my_itoa(int nb)
{
    char *final = malloc(sizeof(char) * (my_numlen(nb) + 2));
    int len1 = my_numlen(nb);

    if (nb == 0 || nb == (-0))
        return "0";
    for (int i = 0; i < my_numlen(nb) + 2; i++)
        final[i] = '\0';
    if (nb < 0) {
        final[0] = '-';
        nb *= -1;
    }
    for (int i = 0; nb > 0; i++) {
        final[len1 - i] = (nb % 10 + '0');
        nb /= 10;
    }
    if (final[0] == '\0')
        return &final[1];
    return final;
}
