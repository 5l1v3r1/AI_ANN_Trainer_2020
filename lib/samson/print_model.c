/*
** EPITECH PROJECT, 2020
** print_model.c
** File description: This file contains a function that allow to visualize
** the model.
*/

#include "samson.h"

void sms_print_layer_model(model_t *model)
{
    layer_t *current = NULL;
    char *nb = NULL;

    my_error("Model layers architecture : ");
    if (model != NULL) {
        current = model->first;
        while (current != NULL) {
            nb = my_int_to_str(current->id);
            my_error(nb);
            my_error(" -> ");
            current = current->next;
            free(nb);
        }
        my_error("NULL\n");
    }
}

void sms_print_neuron_layer(layer_t *layer)
{
    neuron_t *current = NULL;

    if (layer != NULL) {
        current = layer->first;
        while (current != NULL) {
            my_putstr("O\n|\nV\n");
            current = current->next;
        }
        my_putstr("NULL\n");
    }
}