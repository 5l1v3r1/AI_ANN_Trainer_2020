/*
** EPITECH PROJECT, 2019
** task07_my_put_nbr
** File description:
** print a nbr on the terminal
*/

#include "samson.h"

int my_put_nbr(int nb)
{
    int a = 1;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while ((nb / a) >= 10) {
            a *= 10;
        }
        while (a > 0) {
            my_putchar((nb / a) % 10 + '0');
            a /= 10;
        }
    }
    return (0);
}