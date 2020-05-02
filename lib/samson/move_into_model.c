/*
** BELAHOUEL'S PROJECT, 2020
** move_into_model.c
** File description:
** This file contains all the function that allow to find elem in the model.
*/

#include "samson.h"

neuron_t *sms_find_neuron_by_id(layer_t *layer, int id)
{
    neuron_t *current = NULL;

    if (layer == NULL || layer->first == NULL)
        return (NULL);
    current = layer->first;
    while (current != NULL && current->id < id && current->next != NULL) {
        current = current->next;
    }
    if (current->id == id)
        return (current);
    return (NULL);
}

layer_t *sms_find_layer_by_id(model_t *model, int id)
{
    layer_t *current = NULL;

    if (model == NULL || model->first == NULL)
        return (NULL);
    current = model->first;
    while (current != NULL && current->id < id && current->next != NULL) {
        current = current->next;
    }
    if (current->id == id)
        return (current);
    return (NULL);
}