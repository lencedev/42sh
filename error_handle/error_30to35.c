/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_handle_30to35
*/

#include "error_handle.h"

void d_too_many_links_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Too many links.\n", 18);
}

void d_broken_pipe_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Broken pipe.\n", 15);
}

void d_math_args_out_of_domain_of_func_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Math arguments out of domain of func.\n", 40);
}

void d_math_result_not_representable_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Math result not representable.\n", 33);
}

void d_resource_deadlock_would_occur_err(char *tab)
{
    write(2, tab, my_strlen(tab));
    write(2, ": Resource deadlock would occur.\n", 33);
}
