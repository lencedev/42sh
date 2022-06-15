/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** get_cmd
*/

#include "file.h"

void draw_music(void)
{
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠛⠟⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠙⠿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⡿⠏⠁⠄⠄⢀⣴⡆⠄⠄⠄⠄⠄⢠⣦⡀⠄⠄⠈⠙⢿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⡟⠁⢠⡀⠄⠄⡿⠛⠁⠄⠄⠄⠄⠄⠈⠛⣿⣶⣤⣤⡄⠈⢻⣿⣿⣿\n");
    printf("⣿⣿⣿⡿⠄⠄⠈⠁⠄⠄⣴⣦⡄⠄⠄⠄⠄⠄⣠⣴⣤⠈⠉⠉⠁⠄⠄⢿⣿⣿\n");
    printf("⣿⣿⣿⠁⠄⠄⠄⠄⠄⢸⣿⣿⣿⠆⠄⠄⠄⠰⣿⣿⣿⡇⠄⠄⠄⠄⠄⠈⣿⣿\n");
    printf("⣿⣿⣿⠄⠄⠄⠄⠄⠄⠈⠻⠿⠏⠄⠄⠄⠄⠄⠹⠿⠟⠁⠄⠄⠄⠄⠄⠄⣿⣿\n");
    printf("⣿⣿⣿⠄⠄⠄⠄⠄⣀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣀⠄⠄⠄⠄⠄⣿⣿\n");
    printf("⣿⣿⣿⠄⠄⠄⠄⣼⡿⠉⠉⡏⠉⠉⡏⠉⢹⠉⠉⢹⠉⠉⢿⣧⠄⠄⠄⢠⣿⣿\n");
    printf("⣿⣿⣿⡆⠄⠄⠄⢿⣏⠉⠉⡏⠉⠉⡏⠉⢹⠉⠉⢹⠉⠉⣹⡿⠄⠄⠄⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⠄⢠⣄⡈⠛⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠛⢁⣠⡆⠄⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⡄⢸⣿⣷⣤⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⣴⣾⣿⣧⢰⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣤⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
}

int get_cmd(buff_t *buff)
{
    draw_music();
    printf("\t42SHEESH COMMANDS\n\n");
    printf("\"show lib\": display all audio lib\n");
    printf("\n\tget commands\n\n");
    printf("\"get song\": display current playing song\n");
    printf("\"show lib\": display all audio lib\n");
    printf("\n\tplay commands\n\n");
    printf("\"play\":\n-resume if a song has been paused\n");
    printf("-replay if a song is currently played\n");
    printf("-play a random song if a no song is played\n");
    printf("\"play next\": play next song\n");
    printf("\n\tstop / pause commands\n\n");
    printf("\"stop\": stop currently played song\n");
    printf("\"pause\": pause currently played song\n");
    buff->value = 0;
    return 0;
}

int get_song(buff_t *buff)
{
    lib_t *lib = get_current_song(buff->lib_list);
    int len = 0;

    if (check_nb_args(buff->tab, 1) == 0)
        return 1;
    if (my_strcmp(buff->tab[1], "song") == 0 && lib != NULL) {
        len = my_strlen(lib->song.title) - 4;
        printf("Currently playing \"%s\"", my_strndup(lib->song.title, len));
        printf(" of %s.\n", lib->song.artist);
        return 0;
    }
    printf("No song is currently played\n");
    printf("\"-music\" to open command list\n");
    return 1;
}
