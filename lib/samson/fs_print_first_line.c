/*
** EPITECH PROJECT, 2019
** fs_print_first_line.c
** File description:
** This file contain a program that display the first
** line of a file already open on readonly
*/

#include <unistd.h>
#include "samson.h"

void fs_print_first_line(char const *filepath)
{
    int fd = fs_open_file(filepath);
    int n = 1;
    char buffer[1];

    buffer[0] = '0';
    while (n > 0 && buffer[0] != '\n') {
        if (buffer[0] >= 48 && buffer[0] <= 57) {
            n = read(fd, &buffer, 1);
            write(1, &buffer, 1);
        }
    }
    close(fd);
}
