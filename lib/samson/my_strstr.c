/*
** EPITECH PROJECT, 2019
** task05_my_strstr
** File description:
** searchthe first match between string
*/

#include "samson.h"

int matching(char *str, char const *to_find, int i)
{
    for (int j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] != to_find[j]) {
            return (0);
        } else {return (1);}
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int k = 0;
    int n = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        my_putchar('\n');
        if (str[i] == to_find[0]) {
            if (matching(str, to_find, i) == 1) {
                break;
            }
        }
    i++;
    }
    for (; i != 0; i--) {
        str++;
    }
    return (str);
}