/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** init
*/

#include "file.h"

buff_t init_buff(char **env)
{
    buff_t buff = {0};

    buff.env = env;
    init_env(&buff);

    buff.tab = NULL;
    buff.line = NULL;
    buff.len = 0;
    buff.user = "mysh";
    buff.ws = 0;
    return buff;
}
