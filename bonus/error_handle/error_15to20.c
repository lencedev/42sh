/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_15to20
*/

#include "error_handle.h"

void d_device_o_ressource_busy_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Device or ressource busy.\n", 28);
}

void d_file_exists_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": File exists.\n", 15);
}

void d_cross_device_link_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Cross-device link.\n", 21);
}

void d_no_such_device_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": No such device.\n", 18);
}

void d_not_a_dir_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Not a directory.\n", 19);
}
