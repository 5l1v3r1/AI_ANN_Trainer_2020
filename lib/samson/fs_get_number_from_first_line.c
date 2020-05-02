/*
** EPITECH PROJECT, 2019
** fs_get_number_from_first_line.c
** File description:
** This file contains a fonction that will retrieve and return the
** positive number written on the first line of the file passed as parameter.
*/

#include "samson.h"
#include <unistd.h>

int fs_get_number_from_first_line(int fd)
{
    int n = 1;
    int nb = 0;
    char buffer[1];

    buffer[0] = '0';
    if (fd == -1) {
        return (-1);
    }
    while (n > 0 && buffer[0] != '\n') {
        if (buffer[0] >= 48 && buffer[0] <= 57) {
            nb *= 10;
            nb += (buffer[0] - 48);
        } else {
            return (-1);
        }
        n = read(fd, &buffer, 1);
    }
    return (nb);
}