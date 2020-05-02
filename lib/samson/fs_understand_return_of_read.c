/*
** EPITECH PROJECT, 2019
** fs_understand_return_of_read.c
** File description:
** The next function must display a specific
** message according to the read return
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "samson.h"

int fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int n = 0;

    if (fd < 0)
        return (84);
    n = read(fd, buffer, size);
    if (n == -1)
        write(1, "read failed\n", 12);
    if (n == 0)
        write(1, "read has nothing more to read\n", 30);
    if (n < size)
        write(1, "read didn’t complete the entire buffer\n", 42);
    if (n == size)
        write(1, "read completed the entire buffer\n", 34);
    return (0);
}