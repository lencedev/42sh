/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** pwd
*/

#include "file.h"

static const colors_t colors[] = {
    {"\033[31;1m", "\033[5m"},
    {"\033[32;1m", "\033[5m"},
    {"\033[33;1m", "\033[5m"},
    {"\033[34;1m", "\033[5m"},
    {"\033[36;1m", "\033[5m"},
    {"\033[37;1m", "\033[5m"},
    {"\033[31;5m", "\033[5m"},
    {"\033[32;5m", "\033[5m"},
    {"\033[33;5m", "\033[5m"},
    {"\033[34;5m", "\033[5m"},
    {"\033[35;5m", "\033[5m"},
    {"\033[36;5m", "\033[0m"},
};

int add_oldpwd(list_t **env)
{
    list_t *list = *env;
    list_t *old_pwd = find_env_list(list, "OLDPWD");
    list_t *pwd = find_env_list(list, "PWD");

    if (old_pwd != NULL)
        edit_list_value(&old_pwd, "OLDPWD", pwd->value);
    else
        create_node_at_back(env, my_strcat("OLDPWD=", pwd->value));
    return 0;
}

void display_colored_txt(colors_t colors, char *str)
{
    my_putstr(colors.color_1);
    my_putstr(str);
    my_putstr(colors.color_2);
}

void display_pwd(buff_t *buff, char *user)
{
    list_t *tmp = buff->list_env;
    list_t *pwd = find_env_list(tmp, "PWD");
    char *pwd_txt;

    if (pwd) {
        edit_list_value(&pwd, "PWD", buff->cwd);
        pwd_txt = my_strdup(pwd->value);
    }
    else
        pwd_txt = " ";

    display_colored_txt(colors[GREEN], "Sys|");
    display_colored_txt(colors[GREEN], user);
    display_colored_txt(colors[L_GREEN], "@");
    display_colored_txt(colors[GREEN], user);
    display_colored_txt(colors[BLUE], "~");
    display_colored_txt(colors[BLUE], pwd_txt);
    display_colored_txt(colors[BOLD_WHITE], "$");
    display_colored_txt(colors[L_CYAN], " ");
}
