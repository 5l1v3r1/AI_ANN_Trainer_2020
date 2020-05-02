/*
** EPITECH PROJECT, 2019
** my_put_double.c
** File description:
** This function display a double on screen
*/

#include "samson.h"

double my_transform_char_into_double(char *str)
{
    int index = 0;
    int puissance = 1;
    double number = 0.0;

    while (str[index] != '\0') {
        if (str[index] == '.') {
            number *= puissance;
            number = (number + my_transform_char_into_digit(str[index]));
            puissance *= 10;
        }
        number *= puissance;
        number = (number + my_transform_char_into_digit(str[index]));
        puissance *= 10;
        index++;
    }
    str[index] = '\0';
    return (0);
}

int my_put_double(char *str)
{
    int a = 1;
    double number = 0.0;

    number = my_transform_char_into_double(str);
    if (number < 0) {
        my_putchar('-');
    }
    while ((number / a) >= 10) {
        a *= 10;
    }
    while (a > 0) {
        my_putchar(((int)number / a) % 10 + '0');
        a /= 10;
    }
    return (0);
}