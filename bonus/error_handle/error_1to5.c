/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_1to5
*/

#include "error_handle.h"
#include "file.h"

void d_op_not_permitted_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Operation not permitted.\n", 27);
}

void d_no_file_dir_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    if (!access(tab, F_OK)) {
        write(2, ": No such file or directory.\n", 29);
        return;
    }
    write(2, ": Command not found.\n", 21);
}

void d_no_such_process_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": No such process.\n", 19);
}

void d_interrupted_sys_call_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Interrupted system call.\n", 27);
}

void d_i_slash_o_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": I/O error.\n", 13);
}
