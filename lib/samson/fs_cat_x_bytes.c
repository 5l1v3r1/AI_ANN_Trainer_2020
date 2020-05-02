/*
** EPITECH PROJECT, 2019
** fs_cat_500_bytes.c
** File description:
** This file contain a program that cat the
** first 500 char of a file
*/

#include <unistd.h>
#include "samson.h"

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = fs_open_file(filepath);
    int n = 1;
    int i = 0;
    char buffer[1];

    while (n > 0 && i <= x) {
        n = read(fd, &buffer, 1);
        write(1, &buffer, 1);
        i++;
    }
    close(fd);
}