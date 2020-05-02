/*
** EPITECH PROJECT, 2019
** my_put_unint.c
** File description:
** This function print unsigned int
*/

#include "samson.h"

int my_put_unsint(unsigned int number)
{
    int a = 1;

    while ((number / a) >= 10) {
        a *= 10;
    }
    while (a > 0) {
        my_putchar((number / a) % 10 + '0');
        a /= 10;
    }
    return (0);
}
