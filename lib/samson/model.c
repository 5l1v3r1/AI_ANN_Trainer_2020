/*
** EPITECH PROJECT, 2020
** model.c
** File description:
** This file contains all the functions that allow to build models.
*/

#include "samson.h"

float *sms_prepare_dataset(float *dataset, int lenght)
{
    dataset = malloc(sizeof(float) * (lenght + 1));

    if (dataset == NULL)
        return (NULL);
    for (int i = 0; i < lenght; i++)
        dataset[i] = 0.0;
    return (dataset);
}

int sms_give_input_first_lay(model_t *model)
{
    layer_t *input_lay = NULL;
    neuron_t *neuron = NULL;

    if (model == NULL || model->input_set == NULL || model->first == NULL)
        return (ERROR);
    input_lay = model->first;
    if (input_lay->first == NULL)
        return (ERROR);
    neuron = input_lay->first;
    if (neuron == NULL)
        return (ERROR);
    for (int i = 0; i < model->nb_input - 1; i++) {
        if (neuron->next == NULL)
            return (ERROR);
        neuron->prob = model->input_set[i];
        neuron = neuron->next;
    }
    return (SUCCESS);
}

int sms_fill_dataset_user(model_t *model, float *user_dtset, int lenght_u)
{
    if (model == NULL || model->input_set == NULL || user_dtset == NULL) {
        return (ERROR);
    } else if (model->nb_input != lenght_u) {
        return (ERROR);
    }
    for (int i = 0; i < model->nb_input; i++) {
        model->input_set[i] = user_dtset[i];
    }
    if (sms_give_input_first_lay(model) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int sms_prepare_model(model_t *model, int nb_input, int nb_output)
{
    if (model == NULL)
        return (ERROR);
    model->gradient = NULL;
    model->biais = 0;
    model->learning_rate = LEARNING_RATE;
    model->nb_layers = 0;
    model->nb_input = nb_input;
    model->nb_output = nb_output;
    model->input_set = NULL;
    model->output_set = NULL;
    model->result_wanted = NULL;
    model->ann_log = NULL;
    model->loss = 0.0;
    model->accuracy = 0.0;
    model->input_set = sms_prepare_dataset(model->input_set, nb_input);
    model->output_set = sms_prepare_dataset(model->output_set, nb_output);
    model->gradient = sms_prepare_dataset(model->gradient, nb_output);
    if (model->input_set == NULL || model->output_set == NULL
    || model->gradient == NULL)
        return (ERROR);
    return (SUCCESS);
}

model_t *sms_init_model(int nb_input, int nb_output)
{
    model_t *model = malloc(sizeof(model_t));

    if (model == NULL)
        return (NULL);
    model->first = NULL;
    if (sms_prepare_model(model, nb_input, nb_output) == ERROR)
        return (NULL);
    return (model);
}

int sms_rm_model(model_t *model)
{
    layer_t *current = NULL;
    layer_t *to_rm = NULL;
    int nb_lay = 0;
    int i = 0;
    char *str = NULL;
    int statut = SUCCESS;

    my_error("Model Statut : Freeing Memory allocated\n");
    if (model == NULL || model->first == NULL)
        return (ERROR);
    current = model->first;
    while (current->next != NULL) {
        to_rm = current;
        str = my_int_to_str(to_rm->id);
        my_error("Layer number : ");
        my_error(str);
        free(str);
        my_error(": Number neurons free : Expected : ");
        str = my_int_to_str(to_rm->nb_neuron);
        statut += sms_rm_neuron(current);
        current = current->next;
        free(str);
        free(to_rm);
        nb_lay++;
    }
    str = my_int_to_str(current->id);
    my_error("Layer number : ");
    my_error(str);
    my_error(": Number neurons free : Expected : ");
    statut += sms_rm_neuron(current);
    free(current);
    nb_lay++;
    free(str);
    str = my_int_to_str(model->nb_layers);
    if (statut == 0)
        my_error("Model Success : Number layers free correct : Expected : ");
    else
        my_error("Model Error : Number layers free incorrect : Expected : ");
    my_error(str);
    my_error(", Found : ");
    free(str);
    str = my_int_to_str(nb_lay);
    my_error(str);
    my_error("\n");
    free(str);
    if (model->ann_log != NULL) {
        if (model->ann_log[0] != NULL) {
            for (; model->ann_log[i] != NULL; i++)
                free(model->ann_log[i]);
        }
        free(model->ann_log[i]);
        free(model->ann_log);
    }
    if (model->gradient != NULL)
        free(model->gradient);
    if (model->input_set != NULL)
        free(model->input_set);
    if (model->output_set != NULL)
        free(model->output_set);
    free(model);
    return (SUCCESS);
}