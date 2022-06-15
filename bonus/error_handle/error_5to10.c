/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_5to10
*/

#include "error_handle.h"

void d_no_device_o_address_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": No such device or address.\n", 29);
}

void d_arg_list_too_long_rr(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Argument list too long.\n", 26);
}

void d_exec_format_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Exec format error. Wrong Architecture.\n", 42);
}

void d_bad_file_nb_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Bad file number.\n", 19);
}

void d_no_child_processes_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": No child processes.\n", 22);
}
