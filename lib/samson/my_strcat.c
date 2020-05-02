/*
** EPITECH PROJECT, 2019
** task00_my_strcat
** File description:
** je ne sais pas
*/

#include "samson.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    int lenght_src = 0;
    int lenght_dest = 0;
    char *final = NULL;
    int n = 0;

    if (src != NULL && src[0] != '\0')
        lenght_src = my_strlen(src);
    if (dest != NULL && dest[0] != '\0')
        lenght_dest = my_strlen(dest);
    final = malloc(sizeof(char) * (lenght_dest + lenght_src + 1));
    if (final != NULL) {
        for (int i = 0; i < lenght_dest + lenght_src; i++)
            final[i] = 0;
        for (; n < lenght_dest; n++)
            final[n] = dest[n];
        for (int k = 0; k < lenght_src; k++, n++)
            final[n] = src[k];
        final[n] = 0;
    }
    free(dest);
    free(src);
    return (final);
}
