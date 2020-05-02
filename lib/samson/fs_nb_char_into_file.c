/*
** EPITECH PROJECT, 2020
** my_file_char_count.c
** File description:
** This file cotnains a function that count the total of
** char contains into a file.
*/

#include "samson.h"
#include <unistd.h>
#include <stdlib.h>

int fs_nb_char_into_file(char *file_name)
{
    int fd = fs_open_file(file_name);
    size_t read_size = 12;
    int nb_read = read_size;
    char *buff = NULL;
    int count = 0;

    buff = malloc(sizeof(char) * (read_size + 1));
    for (int i = 0; i < read_size; i++)
        buff[i] = 0;
    while (read_size == nb_read) {
        nb_read = read(fd, buff, read_size);
        count += nb_read;
    }
    free(buff);
    close(fd);
    return (count);
}