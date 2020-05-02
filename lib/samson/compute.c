/*
** EPITECH PROJECT, 2020
** compute.c
** File description:
** This file contains all the function that
** compute result for neuronal network.
*/

#include "samson.h"

float *retropropagation(float *array, int lenght, float gradient, float lr)
{
    float biais = 0.0;
    int neg = FALSE;

    if (gradient < 0) {
        gradient *= -1;
        neg = TRUE;
    }
    for (int i = 0; i < lenght; i++) {
        if (neg)
            array[i] = array[i] - (gradient * lr);
        else if (gradient > 0.6)
            array = sms_clean_float_array(array, lenght);
        else
            array[i] = array[i] + (gradient * lr);
    }
    return (array);
}

float sms_somme(float som_nrn_lay2, float prob_nrn_lay1, float wgth_nrn_lay2)
{
    som_nrn_lay2 = som_nrn_lay2 + (prob_nrn_lay1 * wgth_nrn_lay2);

    return (som_nrn_lay2);
}

float sms_activation(float som)
{
    float sp = 0.0;
    float activation = 0.0;
    float biais = sms_random_float(-1, 1, 3);

    sp = biais + som;
    activation = 1/(1 + sms_exp(-sp));
    return (activation);
}

float sms_compute_gradient(float ml_activate, float result_activate)
{
    float gradient = 0.0;

    gradient = (result_activate - ml_activate);
    gradient *= gradient;
    return (gradient);
}