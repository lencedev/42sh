/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** pause_stop_songs
*/

#include "file.h"

int pause_song(buff_t *buff)
{
    lib_t *lib = get_current_song(buff->lib_list);
    int len = 0;

    if (lib) {
        len = my_strlen(lib->song.title) - 4;
        sfMusic_pause(lib->song.music);
        printf("\"%s\" has been paused.\n", my_strndup(lib->song.title, len));
        return 0;
    }
    printf("There is no song currently played.\n");
    return 1;
}

int stop_song(buff_t *buff)
{
    lib_t *lib = get_current_song(buff->lib_list);
    int len = 0;

    if (lib) {
        len = my_strlen(lib->song.title) - 4;
        sfMusic_stop(lib->song.music);
        lib->song.status = 0;
        printf("\"%s\" has been stopped.\n", my_strndup(lib->song.title, len));
        return 0;
    }
    printf("There is no song currently played.\n");
}
