/*
** EPITECH PROJECT, 2020
** fs_write_control_file.c
** File description:
** This file contains a function that allow to control output to save state
** into a debug file.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "samson.h"
#include "samson.h"

int fs_open_debug_file(void)
{
    int fd = -1;

    fd = open("ANN_LOG", O_WRONLY | O_APPEND | O_SYNC, 0777);
    if (fd < 0) {
        fd = open("ANN_LOG", O_WRONLY | O_CREAT | O_APPEND | O_SYNC, 0777);
    }
    return (fd);
}

int fs_write_float_debug_file(float nb_to_write)
{
    int fd = fs_open_debug_file();
    char *float_str = my_float_to_str(nb_to_write);

    if (fd < 0) {
        my_error("fail to open/create the debug file\n");
        return (fd);
    }
    write(fd, float_str, my_strlen(float_str));
    free(float_str);
    close(fd);
    return (SUCCESS);
}

int fs_write_debug_file(char *str_to_write, int nb_to_write)
{
    int fd = fs_open_debug_file();
    char *int_str = my_int_to_str(nb_to_write);

    if (fd < 0) {
        my_error("fail to open/create the debug file\n");
        return (fd);
    }
    write(fd, str_to_write, my_strlen(str_to_write));
    if (nb_to_write > 0)
        write(fd, int_str, my_strlen(int_str));
    free(int_str);
    close(fd);
    return (0);
}