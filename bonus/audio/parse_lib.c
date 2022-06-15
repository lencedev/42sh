/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** parse_lib
*/

#include "file.h"
#include <dirent.h>
#include <stdio.h>

lib_t *find_lib_list(lib_t *lib, const char *str)
{
    for (; lib && my_strncmp(lib->song.title, str, my_strlen(str)); )
        lib = lib->next;
    return lib;
}

int check_lib_name(lib_t *lib, const char *title)
{
    for (; lib; lib = lib->next) {
        if (my_strncmp(lib->song.title, title, my_strlen(title)) == 0)
            return 1;
    }
    return 0;
}

lib_t *get_current_song(lib_t *lib)
{
    for (; lib; lib = lib->next) {
        if (lib->song.status)
            return lib;
    }
    return NULL;
}

int parse_audio(buff_t *buff)
{
    char name[256][256];
    DIR *d;
    struct dirent *dir;
    lib_t *env = NULL;
    char *buf = malloc(BUF_SIZE + 1);
    d = opendir("./audio_lib/");

    if (!d)
        return 1;
    while ((dir = readdir(d)) != NULL) {
        buf = strcpy(name[buff->nb_songs],dir->d_name);
        if (buf[0] != '.') {
            buff->ps = get_array_custom(buf, "-");
            create_node_music(&env, buff->ps[0], buff->ps[1], buf);
            buff->nb_songs++;
        }
    }
    buff->lib_list = env;
    closedir(d);
    return 0;
}
