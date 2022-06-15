/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** error_setenv
*/

#include "error_handle.h"
#include "file.h"

int setenv_nb_args(buff_t *buff)
{
    write(buff->cmd.fd[1], "setenv: Too many arguments.\n", 28);
    return 84;
}
