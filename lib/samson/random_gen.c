/*
** EPITECH PROJECT, 2020
** random_gen.c
** File description:
** This file contains a function that,
**  return a random number between to float gives a parameters.
** Remember to init sran().
*/

#include <time.h>
#include "samson.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int sms_random_gen_int(int min, int max)
{
    int random = 0;

    random = rand() % (max - min) + min;
    return (random);
}

float sms_random_float(float min, float max, int nb_dec)
{
    float random = 0;
    int min_int = sms_xposant_ten(min, nb_dec);
    int max_int = sms_xposant_ten(max, nb_dec);

    random = rand() % (max_int - min_int) + min_int;
    nb_dec *= -1;
    random = sms_xposant_ten(random, nb_dec);
    return (random);
}