/*
** EPITECH PROJECT, 2019
** my_mallocer.c
** File description:
** This function have to manage completely the malloc function
*/

#include <stdlib.h>

int *my_mallocer_int(int lenth_wanted)
{
    int count = 0;
    int *result = {0};

    result = malloc(sizeof(int) * (lenth_wanted + 1));
    result[lenth_wanted + 1] = '\0';
    for (count = 0; count < lenth_wanted; count++) {
        result[count] = 1;
    }
    return (result);
}

char *my_mallocer_char(int lenth_wanted)
{
    char *result = {0};
    int count = 0;

    result = malloc(sizeof(char) * (lenth_wanted + 1));
    result[lenth_wanted + 1] = '\0';
    for (count = 0; count < lenth_wanted; count++) {
        result[count] = '0';
    }
    return (result);
}