/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_10to15
*/

#include "error_handle.h"
#include "file.h"

void d_try_again_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Try again.\n", 13);
}

void d_out_of_mem_rr(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Out of memory.\n", 17);
}

void d_perm_denied_err(char *tab)
{
    write(2, tab, my_strlen(tab));

    if (!check_slash(tab)) {
        write(2, ": Command not found.\n", 21);
        return;
    }
    write(2, ": Permission denied.\n", 21);
}

void d_bad_address_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Bad address.\n", 15);
}

void d_block_device_required_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Block device required.\n", 25);
}
