/*
** EPITECH PROJECT, 2020
** my_exp.c
** File description:
** This function return the exponetial of a number.
*/

#include "samson.h"

float exp_neg(float nb)
{
    float result = 0;

    result = 1 / nb;
    return (result);
}

float sms_exp(float nb)
{
    float result = 1;
    int negative = 0;

    if (nb < 0.0) {
        negative = TRUE;
        nb *= -1;
    }
    for (; nb > 0; nb--) {
        if (result >= MAX_FLOAT)
            break;
        result *= EXP;
    }
    if (negative == TRUE)
        result = exp_neg(result);
    return (result);
}
