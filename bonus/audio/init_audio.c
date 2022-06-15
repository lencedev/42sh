/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** init_audio
*/

#include "file.h"

int print_lib1(buff_t buff)
{
    int len = 0;

    printf("\t- AUDIO LIB -\n");
    for (; buff.lib_list; buff.lib_list = buff.lib_list->next) {
        len = strlen(buff.lib_list->song.title);
        printf("%s :", buff.lib_list->song.artist);
        printf(" %s\n", my_strndup(buff.lib_list->song.title, len - 4));
    }
    return 0;
}

int print_lib(buff_t *buff)
{
    if (my_strcmp(buff->tab[1], "lib") == 0)
        print_lib1(*buff);
    return 0;
}

song_t init_song(char *title, char *artist, char *id)
{
    song_t song = {0};

    song.title = my_strdup(title);
    song.artist = my_strdup(artist);
    song.music = sfMusic_createFromFile(my_strcat("./audio_lib/", id));
    return song;
}

void create_node_music(lib_t **env, char *artist, char *title, char *id)
{
    lib_t *node = malloc(sizeof(lib_t));
    lib_t *list = *env;

    node->song = init_song(title, artist, id);
    node->next = NULL;
    if (list) {
        while (list->next)
            list = list->next;
        list->next = node;
    } else
        *env = node;
}
