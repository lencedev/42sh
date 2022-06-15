/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** audio
*/

#ifndef AUDIO_H_
    #define AUDIO_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #define BUF_SIZE 4500

typedef struct song_s {
    sfMusic *music;
    char *artist;
    char *title;
    int status;
} song_t;

typedef struct playlist_s {
    song_t *song;
    struct playlist_s *next;
} playlist_t;

typedef struct lib_s {
    song_t song;
    struct lib_s *next;
} lib_t;

char *open_file(void);

#endif /* !AUDIO_H_ */
