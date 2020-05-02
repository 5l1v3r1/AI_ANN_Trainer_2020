/*
** EPITECH PROJECT, 2020
** my_hidenp.c
** File description:
** This file contains a function that research
** a hiden str in a stack of char.
*/

#include <stdlib.h>
#include "samson.h"

int hidenp(char *to_find, char *stack)
{
    int i = 0;
    int n = 0;
    int find = 0;

    while (to_find[i] != '\0') {
        find = 0;
        while (find == 0 && stack[n] != '\0') {
            if (to_find[i] == stack[n])
                find = 1;
            n++;
        }
        i++;
    }
    if (find == 1)
        return (1);
    else
        return (0);
}

int find_index_array_hidden_wrd(char **presset, char *to_find)
{
    if (presset == NULL || presset[0] == NULL
    || to_find == NULL || to_find[0] == '\0')
        return (FALSE);
    for (int i = 0; presset[i] != NULL; i++) {
        if (hidenp(to_find, presset[i]) == 1)
            return (i);
    }
    my_error("not found\n");
    return (0);
}