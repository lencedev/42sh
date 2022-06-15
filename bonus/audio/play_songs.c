/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** play_songs
*/

#include "file.h"
#include <time.h>

int play_new_song(buff_t *buff, lib_t *lib)
{
    lib_t *current_lib = get_current_song(buff->lib_list);

    if (current_lib != NULL) {
        current_lib->song.status = 0;
        sfMusic_stop(current_lib->song.music);
    }
    if (check_lib_name(buff->lib_list, buff->tab[1])) {
        lib = find_lib_list(buff->lib_list, buff->tab[1]);
        sfMusic_play(lib->song.music);
        lib->song.status = 1;
        printf("Playing \"%s\".\n", lib->song.title);
        return 0;
    }
    return 1;
}

int play_random(buff_t *buff)
{
    lib_t *lib = buff->lib_list;

    srand(time(NULL));
    int r = rand() % buff->nb_songs;
    int len = 0;

    for (int i = 0; i < r ; lib = lib->next)
        i++;
    sfMusic_play(lib->song.music);
    len = my_strlen(lib->song.title) - 4;
    printf("Playing \"%s\".\n", my_strndup(lib->song.title, len));
    lib->song.status = 1;
    return 1;
}

int resume_song(buff_t *buff, lib_t *lib)
{
    int len = my_strlen(lib->song.title) - 4;
    sfMusic_play(lib->song.music);
    printf("Playing \"%s\".\n", my_strndup(lib->song.title, len));
    return 0;
}

int play_next(buff_t *buff, lib_t *lib)
{
    int len = 0;

    if (lib == NULL)
        return play_random(buff);
    len = my_strlen(lib->song.title) - 4;
    sfMusic_stop(lib->song.music);
    printf("\"%s\" has been stopped.\n", my_strndup(lib->song.title, len));
    lib->song.status = 0;
    if (lib->next == NULL)
        return play_random(buff);
    lib = lib->next;
    sfMusic_play(lib->song.music);
    lib->song.status = 1;
    len = my_strlen(lib->song.title) - 4;
    printf("Playing \"%s\".\n", my_strndup(lib->song.title, len));
    return 0;
}

int play_song_ceo(buff_t *buff)
{
    lib_t *lib = get_current_song(buff->lib_list);

    if (check_nb_args(buff->tab, 1) == 0 && lib == NULL)
        return play_random(buff);
    if (buff->tab[1] == NULL)
        return resume_song(buff, lib);
    if (my_strcmp(buff->tab[1], "next") == 0)
        return play_next(buff, lib);
    return play_new_song(buff, lib);
}
