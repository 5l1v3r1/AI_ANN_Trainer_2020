/*
** EPITECH PROJECT, 2019
** my_getnbr_v2.c
** File description:
** This file contains a function that do the same things
** that the normal my_getnbr but also verify if their is an error.
*/

#include <unistd.h>
#include "samson.h"

int my_getnbr_v2(char const *str, int *error)
{
    int number = 0;
    int index = 0;

    if (str[0] == '-' && str[1] != '\0' && str[1] != 'v') {
        index++;
    }
    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
        number = number * 10;
        number = number + my_transform_char_into_digit(str[index]);
        } else if (str[0] == '-' && str[1] == 'v' && str[2] == '\0') {
        *error = 2;
        } else
            *error = 1;
        index++;
    }
    if (str[0] == '-')
        return (-1 * number);
    return (number);
}