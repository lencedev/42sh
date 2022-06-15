/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_35to40
*/

#include "error_handle.h"

void d_file_name_too_long_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": File name too long.\n", 22);
}

void d_no_record_locks_available_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": No record locks available.\n", 29);
}

void d_function_not_implemented_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Function not implemented.\n", 28);
}

void d_dir_not_empty_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Directory not empty.\n", 23);
}

void d_too_many_symbo_links_encountered_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Too many symbolic links encountered.\n", 39);
}
