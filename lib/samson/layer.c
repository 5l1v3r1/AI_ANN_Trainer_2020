/*
** BELAHOEUL LABORATORY'S PROJECT, 2020
** layer.c
** File description:
** This file contains all the functions that allow to build layers.
*/

#include "samson.h"

int sms_layer_lenght(layer_t *layer)
{
    neuron_t *current = NULL;
    int i = 1;

    if (layer == NULL || layer->first == NULL)
        return (0);
    current = layer->first;
    for (; current != NULL && current->next != NULL; i++)
        current = current->next;
    return (i);
}

layer_t *sms_prepare_new_layer(layer_t *new_layer, int id)
{
    new_layer->id = id;
    new_layer->lenght_prev_layer = 0;
    new_layer->nb_neuron = 0;
    new_layer->first = NULL;
    new_layer->next = NULL;
    return (new_layer);
}

int sms_add_layer(model_t *model, int nb_neuron)
{
    layer_t *new_layer = malloc(sizeof(layer_t));
    layer_t *current_layer = NULL;
    int lngt_p_l = 0;

    if (model == NULL || new_layer == NULL)
        return (ERROR);
    current_layer = model->first;
    while (current_layer != NULL && current_layer->next != NULL)
        current_layer = current_layer->next;
    if (current_layer != NULL)
        lngt_p_l = current_layer->nb_neuron + 1;
    new_layer = sms_prepare_new_layer(new_layer, model->nb_layers);
    for (; new_layer->nb_neuron < nb_neuron; new_layer->nb_neuron++) {
        if (sms_add_neuron(new_layer, new_layer->nb_neuron, lngt_p_l, model->ann_log) == ERROR)
            return (ERROR);
    }
    if (current_layer == NULL)
        model->first = new_layer;
    else {
        new_layer->lenght_prev_layer = lngt_p_l;
        current_layer->next = new_layer;
    }
    model->nb_layers += 1;
    return (SUCCESS);
}

int sms_model_from_ann_log(model_t *model, int nb_neuron)
{

}