/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** check_env
*/

#include "file.h"

int is_env(char *tab)
{
    if (my_strncmp(tab, "env", 4) == 0
    || my_strncmp(tab, "setenv", 7) == 0
    || my_strncmp(tab, "unsetenv", 9) == 0)
        return 1;
    else
        return 0;
}

int check_nb_args(char **env, int nb)
{
    int i;

    for (i = 0; env[i]; i++);
    return (i > nb) ? 1 : 0;
}

int check_first_char(char *chilling, char c)
{
    for (; *chilling; *chilling++) {
        if (*chilling == c)
            return 1;
    }
    return 0;
}

int check_setenv_value(char *str_1)
{
    char *bing = "=?/@[\\]^`{}~*0123456789";
    char *chilling = "~{}^[\\@?=:/-,+*";

    for (int i = 0; str_1[i] != '\0'; i++) {
        if (check_first_char(chilling, str_1[i])) {
            write(1, "setenv: Variable name must contain ", 35);
            write(1, "alphanumeric characters.\n", 25);
            return 84;
        }
    }
    return 1;
}

int check_setenv_name(char *str_1)
{
    char *bing = "=?/@[\\]^`{}~*0123456789";
    char *chilling = "~{}^[\\@?=:/-,+*";

    if (check_first_char(bing, str_1[0])) {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    for (int i = 0; str_1[i] != '\0'; i++) {
        if (check_first_char(chilling, str_1[i])) {
            write(1, "setenv: Variable name must contain ", 35);
            write(1, "alphanumeric characters.\n", 25);
            return 0;
        }
    }
    return 1;
}
