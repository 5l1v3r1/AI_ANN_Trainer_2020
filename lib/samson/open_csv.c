/*
** BELAHOUEL INDUSTRIES'S PROJECT, 2020
** open_csv.c
** File description:
** This file contains a function that open a csv file.
** Your data file to load have to end with a ','.
** Ex file.csv : 1,0,1,1,
** Load data :
** char **data = sms_open_csv("data/file.csv");
** Display data :
** sms_display_csv(data);
** Free data memory:
** sms_free_csv(data);
*/

#include "samson.h"
#include <unistd.h>

char *rm_uselesschar(char *str, char to_rm)
{
    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == to_rm)
            str[i] = '\0';
    return (str);
}

char **sms_open_csv(char *filename)
{
    char **file = NULL;

    file = my_file_to_dbl_array(filename, ',');
    for (int i = 0; file[i] != NULL; i++) {
        if (file[i] == NULL)
            return (NULL);
        file[i] = rm_uselesschar(file[i], '\n');
    }
    return (file);
}

void sms_display_csv(char **data)
{
    for (int i = 0; data[i] != NULL; i++)
        my_putstr(data[i]);
}

void sms_free_csv(char **data)
{
    int i = 0;
    for (; data[i] != NULL; i++)
        free(data[i]);
    free(data[i]);
    free(data);
}