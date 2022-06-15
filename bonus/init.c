/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** init
*/

#include "file.h"

lib_t *init_lib(void)
{
    lib_t *lib = malloc(sizeof(lib_t));
    return lib;
}

buff_t init_buff(char **env)
{
    buff_t buff = {0};

    buff.env = env;
    init_env(&buff);

    buff.lib_list = init_lib();
    buff.tab = NULL;
    buff.line = NULL;
    buff.len = 0;
    buff.user = "mysh";
    buff.ws = 0;
    buff.current_song = NULL;
    return buff;
}
