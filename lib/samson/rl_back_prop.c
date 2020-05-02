/*
** EPITECH PROJECT, 2020
** sms_rl_backprop.c
** File description:
** This file contains a function that allow the agent to learn.
*/

#include "samson.h"

int sms_ajust_weights(float *array, int lenght, float ajustement)
{
    if (array == NULL || lenght == 0)
        return (ERROR);
    for (int i = 0; i < lenght - 1; i++) {
        if (array[i] > -1 && array[i] < 1)
            array[i] *= ajustement;
        if (array[i] < -1)
            array[i] = -1.0;
        if (array[i] > 1)
            array[i] = 1;
    }
    return (SUCCESS);
}

int sms_decrease_nrn_strength(model_t *model, int id_nrn)
{
    layer_t *out_lay = sms_find_layer_by_id(model, model->nb_layers - 1);
    neuron_t *guilty_nrn = NULL;

    if (out_lay == NULL)
        return (ERROR);
    guilty_nrn = sms_find_neuron_by_id(out_lay, id_nrn);
    if (guilty_nrn == NULL)
        return (ERROR);
    if (sms_ajust_weights(guilty_nrn->weight,
    out_lay->lenght_prev_layer, 0.9) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int sms_increase_nrn_strength(model_t *model, int id_nrn)
{
    layer_t *out_lay = sms_find_layer_by_id(model, model->nb_layers - 1);
    neuron_t *good_nrn = NULL;

    if (out_lay == NULL)
        return (ERROR);
    good_nrn = sms_find_neuron_by_id(out_lay, id_nrn);
    if (good_nrn == NULL)
        return (ERROR);
    if (sms_ajust_weights(good_nrn->weight,
    out_lay->lenght_prev_layer, 1.1) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int sms_rl_backpropagation(model_t *model, int guilty_nrn)
{
    int result = SUCCESS;

    result = sms_decrease_nrn_strength(model, guilty_nrn);
    // for (int i = 0; i < model->nb_output; i++) {
    //     if (i != guilty_nrn)
    //         result = sms_increase_nrn_strength(model, i);
    // }
    return (result);
}