/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-owen1.bolling
** File description:
** exit
*/

#include "file.h"

void free_musics(buff_t *buff)
{
    for (int i = 0; i < buff->nb_songs; i++) {
        sfMusic_destroy(buff->lib_list->song.music);
        buff->lib_list = buff->lib_list->next;
    }
}

void free_all(buff_t *buff)
{
    free_musics(buff);
}

int exec_exit(buff_t *buff)
{
    exit((buff->tab[1] == NULL) ? 0 : my_getnbr(buff->tab[1]));
}
