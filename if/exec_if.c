/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** exec_if
*/

#include "file.h"

int handle_if(buff_t *buff)
{
    if (check_nb_args(buff->tab, 1) == 0) {
        write(buff->cmd.fd[1], "if: Too few arguments.\n", 24);
        buff->value = 1;
        return 1;
    }
    if (check_nb_args(buff->tab, 2) == 0) {
        write(buff->cmd.fd[1], "if: Empty if.\n", 15);
        buff->value = 1;
        return 1;
    }
    if (buff->tab[1][0] < '0' || buff->tab[1][0] > '9') {
        write(buff->cmd.fd[1], "if: Expression Syntax.\n", 24);
        buff->value = 1;
        return 1;
    }
    return 0;
}

int exec_if(buff_t *buff)
{
    char **new_tab = NULL;
    int nb = 0;

    if (handle_if(buff))
        return 1;
    nb = atoi(buff->tab[1]);
    new_tab = buff->tab+2;
    buff->tab = new_tab;

    if (!nb)
        return 0;
    exec_pipes(buff, buff->cmd.fd);
}
