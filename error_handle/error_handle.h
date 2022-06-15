/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** error_handle
*/

#ifndef ERROR_HANDLE_H_
    #define ERROR_HANDLE_H_
    #include "tools.h"

typedef struct error_s {
    void (*function)(char *);
    int err_code;
} error_t;

void d_op_not_permitted_err(char *tab);
void d_no_file_dir_err(char *tab);
void d_no_such_process_err(char *tab);
void d_interrupted_sys_call_err(char *tab);
void d_i_slash_o_err(char *tab);

void d_no_device_o_address_err(char *tab);
void d_arg_list_too_long_rr(char *tab);
void d_exec_format_err(char *tab);
void d_bad_file_nb_err(char *tab);
void d_no_child_processes_err(char *tab);

void d_try_again_err(char *tab);
void d_out_of_mem_rr(char *tab);
void d_perm_denied_err(char *tab);
void d_bad_address_err(char *tab);
void d_block_device_required_err(char *tab);

void d_device_o_ressource_busy_err(char *tab);
void d_file_exists_err(char *tab);
void d_cross_device_link_err(char *tab);
void d_no_such_device_err(char *tab);
void d_not_a_dir_err(char *tab);

void d_is_a_dir_err(char *tab);
void d_invalid_arg_rr(char *tab);
void d_file_table_overflow_err(char *tab);
void d_too_many_open_files_err(char *tab);
void d_not_a_typewriter_err(char *tab);

void d_text_file_busy_err(char *tab);
void d_file_too_large_err(char *tab);
void d_no_space_left_on_device_err(char *tab);
void d_illegal_seek_err(char *tab);
void d_read_only_file_sys_err(char *tab);

void d_too_many_links_err(char *tab);
void d_broken_pipe_err(char *tab);
void d_math_args_out_of_domain_of_func_err(char *tab);
void d_math_result_not_representable_err(char *tab);
void d_resource_deadlock_would_occur_err(char *tab);

void d_file_name_too_long_err(char *tab);
void d_no_record_locks_available_err(char *tab);
void d_function_not_implemented_err(char *tab);
void d_dir_not_empty_err(char *tab);
void d_too_many_symbo_links_encountered_err(char *tab);

#endif /* !ERROR_HANDLE_H_ */
