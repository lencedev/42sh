/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_20to25
*/

#include "error_handle.h"

void d_is_a_dir_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Is a directory.\n", 18);
}

void d_invalid_arg_rr(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Invalid argument.\n", 20);
}

void d_file_table_overflow_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": File table overflow.\n", 23);
}

void d_too_many_open_files_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Too many open files.\n", 23);
}

void d_not_a_typewriter_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Not a typewriter.\n", 20);
}
