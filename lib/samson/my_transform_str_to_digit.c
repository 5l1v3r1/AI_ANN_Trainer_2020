/*
** EPITECH PROJECT, 2019
** my_transform_str_to_digit.c
** File description:
** This file contain a function that
** transform a str into digit
*/

#include "samson.h"

int my_str_to_digit(char *str)
{
    int nb = 0;
    int index = 0;

    while (str[index] != '\0') {
        nb *= 10;
        nb += (str[index] - 48);
        index++;
    }
    return (nb);
}