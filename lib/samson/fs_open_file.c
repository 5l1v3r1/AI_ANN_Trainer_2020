/*
** EPITECH PROJECT, 2019
** fs_open_file.c
** File description:
** Read a function that
** open a red-only file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "samson.h"
#include "samson.h"

int fs_open_file(char const *filepath)
{
    int status = -1;

    status = open(filepath, O_RDONLY);
    if (status < 0)
        my_putstr("ERROR: Fail open file: Correct name or change rights\n");
    return (status);
}