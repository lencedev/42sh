/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-owen1.bolling
** File description:
** exit
*/

#include "file.h"

int exec_exit(buff_t *buff)
{
    exit((buff->tab[1] == NULL) ? 0 : my_getnbr(buff->tab[1]));
}
