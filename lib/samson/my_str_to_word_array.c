/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** This function take an str and return an 2d array.
*/

#include <stdlib.h>
#include "samson.h"

int count_biggest(char *str)
{
    int n = 0;
    int biggest = 0;

    for (int i = 0; str[i] != '\0'; i++, n++) {
        if (str[i] == ' ' || str[i] == ':' && n > biggest) {
            biggest = n;
            n = 0;
        } else if (str[i] == ' ' || str[i] == ':' )
            n = 0;
    }
    if (biggest == 0 && n > biggest)
        return (n);
    return (biggest);
}

int count_word(char *str)
{
    int word = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == ':' )
            word += 1;
    }
    return (word);
}

void file(char *array, char *str, int *nb_char_alr_hdl)
{
    int i = *nb_char_alr_hdl;
    int n = 0;

    for (; str[n] == ' ' || str[i] == ':' ; n++);
    for (; (str[i] != ' '  && str[i] != ':') && str[i] != '\0'; n++, i++) {
        array[n] = '\0';
        array[n] = str[i];
    }
    array[n] = '\0';
    *nb_char_alr_hdl = i + 1;
}

char **my_str_to_word_array(char *str, int slash_mode_on)
{
    char **array = NULL;
    int nb_char = count_biggest(str);
    int nb_word = count_word(str);
    int nb_char_alr_hdl = 0;

    array = malloc(sizeof(char *) * (nb_word + 1));
    if (array == NULL)
        return (NULL);
    for (int i = 0; i < nb_word; i++) {
        array[i] = NULL;
        array[i] = malloc(sizeof(char) * (nb_char + 1));
        if (array[i] == NULL)
            return (NULL);
    }
    array[nb_word] = NULL;
    for (int i = 0; i < nb_word; i++) {
        file(array[i], str, &nb_char_alr_hdl);
        if (slash_mode_on && array[i][(my_strlen(array[i])) - 1] != '/')
            array[i][(my_strlen(array[i]))] = '/';
    }
    return (array);
}