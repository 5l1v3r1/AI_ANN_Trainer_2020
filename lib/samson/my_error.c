/*
** EPITECH PROJECT, 2019
** my_error.c
** File description:
** This function manage the stderr
*/

#include <unistd.h>
#include "samson.h"

int my_error(const char *str)
{
    write(2, str, my_strlen(str));
    return (0);
}