/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-owen1.bolling
** File description:
** execute_cd
*/

#include "file.h"

void refresh_pwd(buff_t *buff)
{
    list_t *tmp = buff->list_env;
    if (!check_list_name(tmp, "PWD"))
        return;

    list_t *pwd = find_env_list(tmp, "PWD");
    getcwd(buff->cwd, sizeof(buff->cwd));
    edit_list_value(&pwd, "PWD", buff->cwd);
}

int execute_cd(buff_t *buff, char *tab)
{
    if (chdir(tab) == 0) {
        add_oldpwd(&buff->list_env);
        refresh_pwd(buff);
        return 0;
    }
    return 1;
}

int execute_home(buff_t *buff)
{
    list_t *list = buff->list_env;
    list_t *home = find_env_list(list, "HOME");

    if (check_list_name(list, "HOME"))
        return execute_cd(buff, home->value);
}

int exec_cd(buff_t *buff)
{
    list_t *list = buff->list_env;
    list_t *old_pwd = find_env_list(list, "OLDPWD");

    if (buff->tab[1] == NULL || *buff->tab[1] == '~')
        return execute_home(buff);
    if (*buff->tab[1] == '-') {
        if (check_list_name(list, "OLDPWD"))
            return execute_cd(buff, old_pwd->value);
        buff->tab[1] = my_strdup("");
    }
    if (buff->tab[2] != NULL)
        return display_cd_much_args(buff);
    if (execute_cd(buff, buff->tab[1]))
        return display_no_such_cd(buff);
    return 0;
}
