/*
** EPITECH PROJECT, 2020
** my_file_to_dbl_array.c
** File description:
** This file contains a function that parse a file into a char **.
*/

#include <stdlib.h>
#include <unistd.h>
#include "samson.h"

char *clean_array(char *array, int lenght_array)
{
    for (int alpha = 0; alpha < lenght_array; alpha++)
        array[alpha] = 0;
    return (array);
}

char *buffering_file(char *filename)
{
    char *buff = NULL;
    int fd = fs_open_file(filename);
    int nb_char_file = fs_nb_char_into_file(filename);

    buff = malloc(sizeof(char) * (nb_char_file + 1));
    if (buff == NULL)
        return (NULL);
    for (int i = 0; i <= nb_char_file; i++)
        buff[i] = 0;
    read(fd, buff, nb_char_file);
    close(fd);
    return (buff);
}

void give(char *array, char *str, int *nb_char_alr_hdl, char stop)
{
    int i = *nb_char_alr_hdl;
    int n = 0;

    for (; str[i] != '\0' && str[i] == stop; i++);
    for (; str[i] != stop && str[i] != '\0'; n++, i++) {
        array[n] = str[i];
    }
    array[n] = '\0';
    *nb_char_alr_hdl = i + 1;
}

char **my_file_to_dbl_array(char *filename, char stop)
{
    char **array = NULL;
    char *buff = buffering_file(filename);
    int nb_char = my_biggest_word_into_buff(buff, stop);
    int nb_word = my_count_wrd_into_buff(buff, stop), nb_char_alr_hdl = 0;

    array = malloc(sizeof(char *) * (nb_word + 1));
    if (array == NULL)
        return (NULL);
    for (int i = 0; i < nb_word; i++) {
        array[i] = NULL;
        array[i] = malloc(sizeof(char) * (nb_char + 1));
        if (array[i] == NULL)
            return (NULL);
            array[i] = clean_array(array[i], nb_char);
            give(array[i], buff, &nb_char_alr_hdl, stop);
    }
    array[nb_word] = NULL;
    free(buff);
    return (array);
}
