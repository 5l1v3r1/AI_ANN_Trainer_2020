/*
** EPITECH PROJECT, 2020
** neuron.c
** File description:
** This file contains all functions that allow to build neurons.
*/

#include "samson.h"

float *sms_clean_float_array(float *array, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        array[i] = sms_random_float(-1.0, 1.0, 3);
    }
    return (array);
}

neuron_t *sms_prepare_new_neuron(neuron_t *new, int id)
{
    if (new == NULL)
        return (NULL);
    new->id = id;
    new->som = 0.0;
    new->prob = 1.0;
    new->weight = NULL;
    new->next = NULL;
    return (new);
}

neuron_t *sms_get_last_neuron(neuron_t *current)
{
    while (current != NULL && current->next != NULL)
        current = current->next;
    return (current);
}

int sms_rm_neuron(layer_t *layer)
{
    neuron_t *current = NULL;
    neuron_t *to_rm = NULL;
    int nb_nrn = 0;
    char *str = NULL;

    if (layer == NULL || layer->first == NULL)
        return (ERROR);
    current = layer->first;
    while (current->next != NULL) {
        to_rm = current;
        current = current->next;
        free(to_rm->weight);
        free(to_rm);
        nb_nrn++;
    }
    free(current->weight);
    free(current);
    my_error(", Found : ");
    str = my_int_to_str(nb_nrn + 1);
    free(str);
    if (layer->nb_neuron != nb_nrn + 1) {
        my_error(" ==> Layer Error\n");
        return (ERROR);
    }
    my_error(" ==> Layer Success\n");
    return (SUCCESS);
}

int sms_add_neuron(layer_t *layer, int id, int lenght_prev_lay, char **presset)
{
    neuron_t *new_neuron = malloc(sizeof(neuron_t));
    neuron_t *current_neuron = NULL;
    float *weight = NULL;

    if (layer == NULL || new_neuron == NULL)
        return (ERROR);
    new_neuron = sms_prepare_new_neuron(new_neuron, id);
    if (new_neuron == NULL)
        return (ERROR);
    current_neuron = sms_get_last_neuron(layer->first);
    if (presset == NULL || presset[0] == NULL ||
     presset[0][0] == '\0' ) {//|| layer->id == 0) {
        weight = malloc(sizeof(float) * (lenght_prev_lay + 1));
        if (weight == NULL)
            return (ERROR);
        weight = sms_clean_float_array(weight, lenght_prev_lay + 1);
        new_neuron->weight = weight;
    } else {
        weight = sms_load_preset_weight(presset, layer->id + 1, new_neuron->id + 1);
        new_neuron->weight = weight;
    }
    if (current_neuron == NULL)
        layer->first = new_neuron;
    else
        current_neuron->next = new_neuron;
    return (SUCCESS);
}

float sms_get_proba_into_neuron(layer_t *layer, int id)
{
    neuron_t *current = NULL;

    if (layer == NULL || layer->first == NULL)
        return (ERROR);
    current = sms_find_neuron_by_id(layer, id);
    if (current == NULL)
        return (ERROR);
    return (current->prob);
}