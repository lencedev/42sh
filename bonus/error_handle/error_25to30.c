/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_25to30
*/

#include "error_handle.h"

void d_text_file_busy_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Text file busy.\n", 18);
}

void d_file_too_large_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": File too large.\n", 18);
}

void d_no_space_left_on_device_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": No space left on device.\n", 27);
}

void d_illegal_seek_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Illegal seek.\n", 16);
}

void d_read_only_file_sys_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Read-only file system.\n", 22);
}
