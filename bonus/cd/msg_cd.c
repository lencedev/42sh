/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** messages
*/

#include "file.h"

int display_no_such_cd(buff_t *buff)
{
    write(buff->cmd.fd[1], buff->tab[1], my_strlen(buff->tab[1]));
    if (access(buff->tab[1], F_OK) == 0)
        write(buff->cmd.fd[1], ": Not a directory.\n", 19);
    else
        write(buff->cmd.fd[1], ": No such file or directory.\n", 29);
    return 1;
}

int display_cd_much_args(buff_t *buff)
{
    write(buff->cmd.fd[1], "cd: Too many arguments.\n", 24);
    return 1;
}
