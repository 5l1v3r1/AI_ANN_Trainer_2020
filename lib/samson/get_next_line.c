/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** this file contains the get_next_line_fonction
*/

#include "samson.h"

void set_buff(char *buff, int lenght)
{
    for (int index = 0; index < lenght; index++)
        buff[index] = 0;
}

void put_trash(char *save, int letter_alr_hdl, int lenght_save)
{
    char letter = 0;

    for (int i = 0; i < lenght_save; i++) {
        if (i < lenght_save - letter_alr_hdl)
            save[i] = save[letter_alr_hdl + i];
        else
            save[i] = 0;
    }
}

char *more_space(char *line, char *save, int *lenght_save, int fd)
{
    save[*lenght_save + READ_SIZE];
    *lenght_save += READ_SIZE;
    for (int i = 0; i < *lenght_save + READ_SIZE; i++) {
        if (i <= *lenght_save - READ_SIZE)
            save[i] = line[i];
        else
            save[i] = 0;
    }
}

char *start_read(char *line, int fd, char *save, int *lenght_save)
{
    int nb_letter = 0;
    int nb_read = 0;
    int i = 0;
    int n = 0;
    char *buff = NULL;
    char *empty = NULL;

    for (; save[nb_letter] != '\0'; nb_letter++);
    nb_read = *lenght_save - nb_letter;
    buff = malloc(sizeof(char) * nb_read);
    if (buff == NULL)
        return (NULL);
    nb_read = read(fd, buff, *lenght_save - nb_letter);
    if (nb_read == 0 && *lenght_save == 0)
        return (NULL);
    for (int i = 0; i < nb_read; i++, nb_letter++)
        save[nb_letter] = buff[i];
    save[nb_letter] = 0;
    line = malloc(sizeof(char) * nb_letter + 1);
    if (line == NULL)
        return (NULL);
    set_buff(line, nb_letter);
    // for (; save[i] == '\n'; i++);
    if (save[0] == '\n') {
        empty = malloc(sizeof(char) * 1);
        if (empty == NULL)
            return (NULL);
        empty[0] = 0;
        put_trash(save, 1, *lenght_save);
        return (empty);
    }
    for (; save[i] != '\0'; i++, n++) {
        if (save[i] == '\n') {
            put_trash(save, i + 1, *lenght_save);
            return (line);
        }
        line[n] = save[i];
    }
    line[n] = 0;
    if (nb_read < *lenght_save - nb_letter) {
        *lenght_save = 0;
        return (line);
    } else if (nb_read == 0 && lenght_save == 0)
        return (NULL);
    else {
        more_space(line, save, lenght_save, fd);
        save[i] = 0;
        line = malloc(sizeof(char) * (*lenght_save + READ_SIZE));
        if (line == NULL)
            return (NULL);
        set_buff(line, *lenght_save + READ_SIZE);
        line = start_read(line, fd, save, lenght_save);
        free(buff);
        return (line);
    }
}

char *get_next_line(int fd)
{
    char *line = NULL;
    static int lenght_save = READ_SIZE;
    static char save[READ_SIZE + 1] = {0};

    if (fd < 0)
        return (NULL);
    line = start_read(line, fd, save, &lenght_save);
    return (line);
}
