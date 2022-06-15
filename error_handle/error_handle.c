/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_handle
*/

#include <errno.h>
#include "file.h"
#include "error_handle.h"

static const error_t set[] = {
    {d_op_not_permitted_err, 1},
    {d_no_file_dir_err, 2},
    {d_no_such_process_err, 3},
    {d_interrupted_sys_call_err, 4},
    {d_i_slash_o_err, 5},
    {d_no_device_o_address_err, 6},
    {d_arg_list_too_long_rr, 7},
    {d_exec_format_err, 8},
    {d_bad_file_nb_err, 9},
    {d_no_child_processes_err, 10},
    {d_try_again_err, 11},
    {d_out_of_mem_rr, 12},
    {d_perm_denied_err, 13},
    {d_bad_address_err, 14},
    {d_block_device_required_err, 15},
    {d_device_o_ressource_busy_err, 16},
    {d_file_exists_err, 17},
    {d_cross_device_link_err, 18},
    {d_no_such_device_err, 19},
    {d_not_a_dir_err, 20},
    {d_is_a_dir_err, 21},
    {d_invalid_arg_rr, 22},
    {d_file_table_overflow_err, 23},
    {d_too_many_open_files_err, 24},
    {d_not_a_typewriter_err, 25},
    {d_text_file_busy_err, 26},
    {d_file_too_large_err, 27},
    {d_no_space_left_on_device_err, 28},
    {d_illegal_seek_err, 29},
    {d_read_only_file_sys_err, 30},
    {d_too_many_links_err, 31},
    {d_broken_pipe_err, 32},
    {d_math_args_out_of_domain_of_func_err, 33},
    {d_math_result_not_representable_err, 34},
    {d_resource_deadlock_would_occur_err, 35},
    {d_file_name_too_long_err, 36},
    {d_no_record_locks_available_err, 37},
    {d_function_not_implemented_err, 38},
    {d_dir_not_empty_err, 39},
    {d_too_many_symbo_links_encountered_err, 40},
};

int display_error(char *tab, int *err_code)
{
    set[*err_code - 1].function(tab);
    return 84;
}
