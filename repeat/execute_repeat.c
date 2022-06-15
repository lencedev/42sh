/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** execute_repeat
*/

#include "file.h"

int check_repeat_errors(buff_t *buff)
{
    if (check_nb_args(buff->tab, 2) == 0) {
        write(buff->cmd.fd[1], "repeat: Too few arguments.\n", 27);
        buff->value = 1;
        return 1;
    }
    if (atoi(buff->tab[1]) == 0) {
        write(buff->cmd.fd[1], "repeat: Badly formed number.\n", 29);
        buff->value = 1;
        return 1;
    }
    return 0;
}

int exec_repeat(buff_t *buff)
{
    char **new_tab = NULL;
    int nb = 0;

    if (check_repeat_errors(buff))
        return 1;
    nb = atoi(buff->tab[1]);
    new_tab = buff->tab+2;
    buff->tab = new_tab;

    for (int i = 0; i < nb; i++)
        exec_pipes(buff, buff->cmd.fd);
}
