/*
** EPITECH PROJECT, 2019
** my_get_nbr
** File description:
** search in a string a number and return it on int
*/

#include "samson.h"
#include <unistd.h>

int my_getnbr(char const *str)
{
    int number = 0;
    int index = 0;
    if (str[0] == '-' && str[1] != '\0') {
        index++;
    }
    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
        number = number * 10;
        number = number + my_transform_char_into_digit(str[index]);
        } else {
            write (2, "IT MUST BE ONLY DIGITS INTO THIS STRING\n", 40);
        }
        index++;
    }
    if (str[0] == '-') {
        return (-1 * number);
    }
    return (number);
}