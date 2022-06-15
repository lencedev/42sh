/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-bsminishell1-owen1.bolling
** File description:
** main
*/

#include "file.h"
#include <curses.h>

const exec_cmd_t set[NB_BUILT_IN] = {
    {exec_exit, "exit"},
    {exec_cd, "cd"},
    {exec_env, "env"},
    {exec_setenv, "setenv"},
    {exec_unsetenv, "unsetenv"},
    {exec_alias, "alias"},
    {exec_where, "where"},
    {exec_var, "set"},
    {exec_unset, "unset"},
    {exec_unalias, "unalias"},
    {exec_repeat, "repeat"},
    {print_lib, "show"},
    {play_song_ceo, "play"},
    {stop_song, "stop"},
    {pause_song, "pause"},
    {get_song, "get"},
    {get_cmd, "-music"},
};

void shell_name(void)
{
    printf("  _ _ ___ ___ _  _ ___ ___ ___ _  _ \n");
    printf(" | | |_  ) __| || | __| __/ __| || |\n");
    printf(" |_  _/ /\\__ \\ __ | _|| _|\\__ \\ __ |\n");
    printf("   |_/___|___/_||_|___|___|___/_||_|\n");
    printf("\n");
}

int handle_signal(int ws)
{
    int a = WTERMSIG(ws);
    char *str = strsignal(a);

    write(1, str, my_strlen(str));

    if (WCOREDUMP(ws)) {
        write(1, "(core dumped)", 13);
        write(1, "\n", 1);
    }
    return 1;
}

int exec_ceo(buff_t *buff, int fd[2])
{
    buff->cmd.fd = fd;
    buff->tab = get_array(my_strdup(buff->cmd.cmd));

    find_alias(buff);

    if (find_var(buff))
        return 1;

    for (int i = 0; i != NB_BUILT_IN; i++)
        if (my_strcmp(*buff->tab, set[i].name) == 0) {
            buff->value = set[i].function(buff);
            return buff->value;
        }
    return (exec_pipes(buff, fd) != 0) ? handle_signal(buff->ws) : 0;
}

int checker(char *str)
{
    char **array = get_array(my_strdup(str));

    return (*array) ? 1 : 0;
}

int main(int ac, char **av, char **env)
{
    buff_t buff = init_buff(env);
    parse_audio(&buff);
    shell_name();
    while (1) {
        if (isatty(0) && getcwd(buff.cwd, sizeof(buff.cwd)) != NULL)
            display_pwd(&buff, buff.user);

        my_getline(&buff);
        if (buff.line != NULL)
            buff.value = coma_separator_manager(&buff);
    }
    return buff.value;
}
