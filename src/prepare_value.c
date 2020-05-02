/*
** EPITECH PROJECT, 2020
** prepare_value.c
** File description:
** This file contains all the function that prepare value.
*/

#include "samson.h"
#include "ann_trainer.h"

float *ascii_dataset_to_float_arr(char **array, int lenght_wanted, int start)
{
    float *result = NULL;

    if (array == NULL || array[0] == NULL || array[0][0] == 0)
        return (NULL);
    result = malloc(sizeof(float *) * (lenght_wanted + 1));
    if (result == NULL)
        return (NULL);
    for (int current = 0;
    array[start] != NULL && current < lenght_wanted; current++, start++) {
        result[current] = 0;
        result[current] = my_str_to_float(array[start]);
    }
    result[lenght_wanted] = 0;
    return (result);
}