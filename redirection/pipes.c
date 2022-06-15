/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-owen1.bolling
** File description:
** pipes
*/

#include "file.h"

extern const exec_cmd_t set[NB_BUILT_IN];

void close_fd(int *fd)
{
    if (fd[0] != STDIN_FILENO)
        close(fd[0]);
    if (fd[1] != STDOUT_FILENO)
        close(fd[1]);
    return;
}

int pipes_error(buff_t *buff, char **parsed)
{
    if (count_parse(buff->cmd.cmd, '|') > 2)
        return 1;
    for (int i = 0; i != NB_BUILT_IN; i++)
        if (my_strcmp(parsed[0], my_strdup(set[i].name)) == 0)
            return 1;
    return 0;
}

int exec_pipes(buff_t *buff, int fd[2])
{
    char *bing = find_cmd(buff);
    pid_t pid = fork();

    if (pid == 0) {
        dup2(fd[0], STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        if (!pid && execve(bing, buff->tab, buff->env) == -1)
            exit(display_error(bing, &errno));
    }
    if (pid && waitpid(pid, &buff->ws, 0) == -1)
        exit(84);
    close_fd(fd);
    buff->value = WEXITSTATUS(buff->ws);
    return 0;
}

int pipes_manager(buff_t *buff, int fd[2])
{
    char **parsed = NULL;

    if (count_parse(buff->cmd.cmd, '|') < 2)
        return parsing_redirect(buff, fd);
    pipe(fd);
    parsed = parsing_line(buff->cmd.cmd, '|');
    if (pipes_error(buff, parsed))
        return 1;
    if (parsed[0]) {
        buff->cmd.cmd = my_strdup(parsed[0]);
        parsing_redirect(buff, (int [2]) {STDIN_FILENO, fd[1]});
    }
    if (parsed[1]) {
        buff->cmd.cmd = my_strdup(parsed[1]);
        parsing_redirect(buff, (int [2]) {fd[0], STDOUT_FILENO});
    }
    return buff->value;
}
