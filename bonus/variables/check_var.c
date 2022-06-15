/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** check_var
*/

#include "file.h"

int check_list_var_name(list_t *env, const char *name)
{
    char *var_name = NULL;

    for (; env; env = env->next) {
        var_name = my_strcat("$", env->name);
        if (my_strncmp(var_name, name, my_strlen(name)) == 0)
            return 1;
    }
    return 0;
}

list_t *find_var_list(list_t *env, const char *str)
{
    while (env && my_strncmp(my_strcat("$", env->name), str, my_strlen(str)))
        env = env->next;
    return env;
}

int check_var_name(char *str_1)
{
    char *bing = "=?/@[\\]^`{}~*0123456789";
    char *chilling = "~{}^[\\@?=:/-,+*";

    if (check_first_char(bing, str_1[0])) {
        write(1, "set: Variable name must begin with a letter.\n", 44);
        return 0;
    }
    for (int i = 0; str_1[i] != '\0'; i++) {
        if (check_first_char(chilling, str_1[i])) {
            write(1, "set: Variable name must contain ", 32);
            write(1, "alphanumeric characters.\n", 25);
            return 0;
        }
    }
    return 1;
}
