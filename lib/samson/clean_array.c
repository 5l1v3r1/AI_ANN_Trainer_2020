/*
** EPITECH PROJECT, 2020
** clean_array.c
** File description:
** This file contains a function that llow to clean an array of char.
*/

char *sms_clean_array(char *str, int lenght)
{
    for (int i = 0; i < lenght; i++)
        str[i] = 0;
    return (str);
}