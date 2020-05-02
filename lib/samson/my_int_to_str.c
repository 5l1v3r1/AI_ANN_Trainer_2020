/*
** EPITECH PROJECT, 2020
** my_int_to_str.c
** File description:
** This file contains a function that take a number and turn it into an str.
** Dont forget to free the str.
*/

#include <unistd.h>
#include <stdlib.h>

char *int_to_str(int nb)
{
    char *str = NULL;
    int expos = 1;
    int i = 0;

    str = malloc(sizeof(char) * 16);
    if (str == NULL)
        return (NULL);
    for (int i = 0; i < 16; i++)
        str[i] = 0;
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb *= -1;
    }
    for(; (nb / expos) >= 10; expos *= 10);
    for (;  expos > 0; i++) {
        str[i] = (nb / expos) % 10 + 48;
        expos /= 10;
    }
    return (str);
}