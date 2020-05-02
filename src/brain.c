/*
** EPITECH PROJECT, 2020
** brain.c
** File description:
** This file contains all the ANN.
*/

#include "time.h"
#include "ann_trainer.h"
#include "samson.h"

int sms_add_mutation(model_t *model, int percent_mutation)
{
    layer_t *l = NULL;
    neuron_t *n = NULL;
    int mutation = (TOTAL_NRN * percent_mutation) / 100;
    int random = 0;

    my_error("Model : Starting to add mutations...\n");
    while (mutation > 0) {
        random = sms_random_gen_int(1, model->nb_layers);
        l = sms_find_layer_by_id(model, random);
        if (l == NULL)
           return (ERROR);
        random = sms_random_gen_int(0, l->nb_neuron);
        n = sms_find_neuron_by_id(l, random);
        if (n == NULL)
            return (ERROR);
        n->weight = sms_clean_float_array(n->weight, l->lenght_prev_layer - 1);
        mutation--;
    }
    return (SUCCESS);
}

int sms_add_mutation_spec_nrn(model_t *model, int id_lay, int id_nrn, int perc)
{
    layer_t *l = NULL;
    neuron_t *n = NULL;
    int mutation = 0;
    int random = 0.0;

    l = sms_find_layer_by_id(model, id_lay);
    n = sms_find_neuron_by_id(l, id_nrn);
    if (n == NULL)
        return (ERROR);
    mutation = (l->lenght_prev_layer * perc) / 100;
    while (mutation > 0) {
        random = sms_random_gen_int(0, l->lenght_prev_layer - 1);
        n->weight[random] = sms_random_float(-1, 1, 3);
        mutation--;
    }
    return (SUCCESS);
}

int brain(ann_trainer_t *ann_trainer)
{
    int result = SUCCESS;
    srand(time(NULL));
    int nb_output = 1;
    model_t *model = sms_init_model(ann_trainer->nb_input, nb_output);

    if (model == NULL)
        return (ERROR);

    //LOAD LAST BRAIN
    model->ann_log = ann_trainer->ann;

    //BUILD BRAIN BASE ON ANN_LOG
    result = sms_add_layer(model, ann_trainer->nb_input);

    // model = build_ann(model);
    if (model == NULL)
        return (ERROR);
    result = sms_add_layer(model, nb_output);
    if (result == ERROR)
        return (ERROR);

    //FITTING RESULT
    result = sms_fit_model(model, "sigmoid", ann_trainer);
    sms_print_layer_model(model);
    sms_rm_model(model);
    return (SUCCESS);
}