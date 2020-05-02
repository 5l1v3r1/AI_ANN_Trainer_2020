/*
** EPITECH PROJECT, 2019
** my_transform_int_into_str.c
** File description:
** Transform a int into a str.c
*/

#include "samson.h"
#include <stdlib.h>
char *my_int_to_str(int nb)
{
    char *result = NULL;
    int stop = 0;
    int lenght_nb = 0;

    if (nb < 0) {
        stop += 1;
        nb *= -1;
        lenght_nb = my_nbrlen(nb);
        result = malloc(sizeof(char) * (lenght_nb + 2));
        if (result == NULL)
            return (NULL);
        result[0] = '-';
    } else {
        lenght_nb = my_nbrlen(nb);
        result = malloc(sizeof(char) * (lenght_nb + 1));
        if (result == NULL)
            return (NULL);
    }
    result[lenght_nb + stop] = '\0';
    for (int i = stop + lenght_nb - 1; i >= stop; i--) {
        result[i] = (nb % 10) + 48;
        nb /= 10;
    }
    return (result);
}