/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** This function duplicate a string
*/

#include "samson.h"

char *my_strdup(char *str)
{
    char *duplicate = {0};

    duplicate = my_mallocer_char(my_strlen(str));
    duplicate = my_strcpy(duplicate, str);
    return (duplicate);
}
