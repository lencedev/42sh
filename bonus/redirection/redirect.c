/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-owen1.bolling
** File description:
** redirect
*/

#include "file.h"

int redirect_input_manager(buff_t *buff, int fd[2])
{
    char **parsed = parsing_line(buff->cmd.cmd, '<');
    char **parsed2 = parsing_line(buff->cmd.cmd, '<');
    char *output = parse_output(parsed);
    char *cmd = parse_cmd(parsed2);

    if (parsed[0]) {
        int file = open(output, O_RDONLY);
        if (file == -1)
            return 2;
            buff->cmd.cmd = my_strdup(cmd);
            buff->value = exec_ceo(buff, (int [2]) {file, STDOUT_FILENO});
        }
    return buff->value;
}

int redirect_double_input_manager(buff_t *buff, int fd[2])
{
    char **parsed = get_array_custom(buff->cmd.cmd, "<<");
    char **parsed2 = get_array_custom(buff->cmd.cmd, "<<");
    char *output = parse_output(parsed);
    char *cmd = parse_cmd(parsed2);

    if (parsed[0]) {
        int file = open(output, O_APPEND | O_RDONLY);
        if (file == -1)
            return 0;
            buff->cmd.cmd = my_strdup(cmd);
            buff->value = exec_ceo(buff, (int [2]) {file, STDOUT_FILENO});
        }
    return 0;
}

int redirect_output_manager(buff_t *buff, int fd[2])
{
    char **parsed = parsing_line(buff->cmd.cmd, '>');
    char **parsed2 = parsing_line(buff->cmd.cmd, '>');
    char *output = parse_output(parsed);
    char *cmd = parse_cmd(parsed2);

    if (parsed[1]) {
        int file = open(output, O_WRONLY | O_CREAT, 0777);
        if (file == -1)
            return 2;
        if (parsed[0]) {
            buff->cmd.cmd = my_strdup(cmd);
            buff->value = exec_ceo(buff, (int [2]) {STDIN_FILENO, file});
        }
    }
    return buff->value;
}

int redirect_double_output_manager(buff_t *buff, int fd[2])
{
    char **parsed = get_array_custom(buff->cmd.cmd, ">>");
    char **parsed2 = get_array_custom(buff->cmd.cmd, ">>");
    char *output = parse_output(parsed);
    char *cmd = parse_cmd(parsed2);

    if (parsed[1]) {
        int file = open(output, O_APPEND | O_WRONLY | O_CREAT, 0777);
        if (file == -1)
            return 0;
        if (parsed[0]) {
            buff->cmd.cmd = my_strdup(cmd);
            buff->value = exec_ceo(buff, (int [2]) {STDIN_FILENO, file});
        }
    }
    return 0;
}

int parsing_redirect(buff_t *buff, int fd[2])
{
    if (count_parse(buff->cmd.cmd, '>') == 2)
        return redirect_output_manager(buff, fd);
    if (count_parse(buff->cmd.cmd, '<') == 2)
        return redirect_input_manager(buff, fd);
    if (count_multi_parses(buff->cmd.cmd, ">>") > 1)
        return redirect_double_output_manager(buff, fd);
    if (count_multi_parses(buff->cmd.cmd, "<<") > 1)
        return redirect_double_input_manager(buff, fd);
    if (buff->cmd.cmd)
        exec_ceo(buff, fd);
    return buff->value;
}
