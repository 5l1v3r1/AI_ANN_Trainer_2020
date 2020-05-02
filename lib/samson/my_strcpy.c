/*
** EPITECH PROJECT, 2019
** task01_my_strcpy
** File description:
** copy a string into another
*/

#include "samson.h"

char *my_strcpy(char *dest, char const *src)
{
    int p = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++, p++) {
        dest[p] = src[i];
    }
    dest[p] = '\0';
    return (dest);
}