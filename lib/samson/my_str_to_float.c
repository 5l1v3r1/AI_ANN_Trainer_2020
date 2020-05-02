/*
** EPITECH PROJECT, 2020
** my_str_to_float.c
** File description:
** This file contains a function that conver an str into float.
*/

#include "samson.h"

float my_str_to_float(char *str_num)
{
    float result = 0;
    int point = 0;
    int decimal = 0;
    int negativ = 0;

    if (str_num[0] == '-')
        negativ = 1;
    for (int n = 0; str_num[n] != '\0'; n++) {
        if (point == 1)
            decimal += 1;
        if (str_num[n] == '.')
            point = 1;
    }
    for (int n = 0; str_num[n] != '\0'; n++) {
        if (str_num[n] >= '0' && str_num[n] <= '9') {
            result *= 10;
            result += str_num[n] - 48;
        }
    }
    decimal *= -1;
    result = sms_xposant_ten(result, decimal);
    if (negativ == 1)
        return (result * -1);
    return (result);
}

char *my_float_to_str(float nb)
{
    int nb_int = nb;
    char *str_int = my_int_to_str(nb_int);
    int lenght_int_part = my_strlen(str_int);
    char *final = NULL;

    final = malloc(sizeof(char) * (1 + lenght_int_part + 1 + 3 + 1));
    if (final == NULL)
        return (NULL);
    for (int i = 0; i < lenght_int_part + 5; i++)
        final[i] = 0;
    if (nb < 0 && str_int[0] != '-') {
        final[0] = '-';
        nb *= -1;
    }
    final = my_strcpy(final, str_int);
    lenght_int_part = my_strlen(final);
    final[lenght_int_part] = '.';
    nb -= nb_int;
    nb += 1;
    nb_int = sms_xposant_ten(nb, 3);
    nb_int -= 1000;
    free(str_int);
    str_int = my_int_to_str(nb_int);
    if (my_strlen(str_int) == 2)
        final[my_strlen(final)] = '0';
    final = my_strcpy(final, str_int);
    lenght_int_part = my_strlen(final);
    final[lenght_int_part] = '\0';
    free(str_int);
    return (final);
}