/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-romain.very
** File description:
** set_termios
*/

#include "file.h"

static void reset_terminal(terminal_t *terminal)
{
    if (terminal->fd != -1)
        tcsetattr(terminal->fd, TCSANOW, &terminal->original);
}

static int init_terminal(terminal_t *terminal)
{
    if (terminal->fd != -1)
        return 0;
    if (isatty(STDIN_FILENO))
        terminal->fd = STDIN_FILENO;
    else
        return errno = ENOTTY;
    if (tcgetattr(terminal->fd, &terminal->original) ||
        tcgetattr(terminal->fd, &terminal->settings))
        return errno = ENOTSUP;
    if (isatty(STDIN_FILENO))
        setvbuf(stdin, NULL, _IONBF, 0);
    if (atexit(reset_terminal))
        return errno = ENOTSUP;
    terminal->settings.c_iflag &= ~(INLCR | IGNCR | ICRNL | ISTRIP | PARMRK);
    terminal->settings.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL);
    terminal->settings.c_cc[VTIME] = 0;
    terminal->settings.c_cc[VMIN] = 1;
    tcsetattr(terminal->fd, TCSANOW, &terminal->settings);
    return 0;
}

int key_intput(buff_t *buff)
{
    int c = 0;
    int f = 0;

    if (init_terminal(buff->terminal)) {
        if (errno == ENOTTY)
            return 84;
    }
    while ((c = getchar()) != EOF && (f = getchar()) != EOF) {
        f = getchar();
        if (c == '\033' && f == 66)
            printf("KEY_DOWN\n");
        if (c == '\033' && f == 65)
            printf("KEY_UP\n");
        if (c == '\033' && f == 67)
            printf("KEY_RIGHT");
        if (c == '\033' && f == 68)
            printf("KEY_LEFT");
    }
    return 0;
}
