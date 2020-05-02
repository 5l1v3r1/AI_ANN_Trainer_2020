/*
** EPITECH PROJECT, 2020
** compil_model.c
** File description:
** This file contains all the function that allow to compil and test the model.
*/

#include "samson.h"
#include "ann_trainer.h"

int sms_try_layers(model_t *model, int nb_layers_expected)
{
    int result = SUCCESS;
    int layers_found = 0;

    write(1, "Verifying layers...\n", 20);
    if (model == NULL || model->first == NULL)
        return (ERROR);
    for (; sms_find_layer_by_id(model, layers_found) != NULL; layers_found++);
    if (layers_found != nb_layers_expected) {
        write(1, "Model Error : Number layers incorrect : Expected : ", 51);
        result = ERROR;
    } else
        write(1, "Model Sucess : Number layers correct : Expected : ", 50);
    my_put_nbr(nb_layers_expected);
    write(1, ", Found : ", 10);
    my_put_nbr(layers_found);
    my_putchar('\n');
    return (SUCCESS);
}

int sms_try_neurons(model_t *model)
{
    int nrn_found = 0;
    layer_t *current = NULL;

    write(2, "Verifying neurons...\n", 21);
    if (model == NULL || model->first == NULL)
        return (ERROR);
    for (int i = 0; i < model->nb_layers; i++) {
        current = sms_find_layer_by_id(model, i);
        write(1, "Layer number : ", 15);
        my_put_nbr(i);
        if (current == NULL)
            return (ERROR);
        nrn_found = 0;
        for (; sms_find_neuron_by_id(current, nrn_found) != NULL; nrn_found++);
        write(2, " : Number neurons : Expected : ", 31);
        my_put_nbr(current->nb_neuron);
        write(2, ", Found : ", 10);
        my_put_nbr(nrn_found);
        if (nrn_found != current->nb_neuron) {
            write(2, " ==> Layer Error\n", 17);
            return (ERROR);
        }
        write(2, " ==> Layer Success\n", 19);
    }
    return (SUCCESS);
}

int sms_try_model(model_t *model)
{
    int result = SUCCESS;

    write(2, "Verifying model...\n", 19);
    if (model == NULL || model->first == NULL)
        result = ERROR;
    result = sms_try_layers(model, model->nb_layers);
    if (result == ERROR)
        return (ERROR);
    result = sms_try_neurons(model);
    return (result);
}

int sms_compile_model(model_t *model)
{
    write(2, "Using Samson, made by Sofian Belahouel.\n", 40);
    if (sms_try_model(model) == ERROR) {
        write(2, "Model Compilation : Error\n", 27);
        return (ERROR);
    }
    write(2, "Model Compilation : Success\n", 28);
    return (SUCCESS);
}

int sms_get_eatch_nrn(layer_t *current_lay, model_t *model)
{
    neuron_t *nrn = NULL;
    int lgt = 0;
    float lr = model->learning_rate;

    for (int i = 0; i < current_lay->nb_neuron; i++) {
        nrn = sms_find_neuron_by_id(current_lay, i);
        if (nrn == NULL)
            return (ERROR);
        lgt = current_lay->lenght_prev_layer;
        nrn->weight = retropropagation(nrn->weight, lgt, model->gradient[0], lr);
    }
    return (SUCCESS);
}

int sms_learn(model_t *model)
{
    layer_t *current_lay = NULL;

    for (int i = 0; i < model->nb_layers; i++) {
        current_lay = sms_find_layer_by_id(model, i);
        if (current_lay == NULL
        || sms_get_eatch_nrn(current_lay, model) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}

int get_index_line(char **presset, int nb_layer, int nb_neuron)
{
    int to_malloc = ((my_nbrlen(nb_layer)) + (my_nbrlen(nb_neuron)) + 2 + 1);
    char *to_add = my_int_to_str(nb_layer);
    int index = 0;
    char *to_find = NULL;

    to_find = malloc(sizeof(char) * (to_malloc));
    if (to_find == NULL)
        return (0);
    for (int n = 0; n < to_malloc; n++)
        to_find[n] = 0;
    to_find[0] = 'L';
    to_find = my_strcpy(to_find, to_add);
    to_find[my_strlen(to_find)] = 'N';
    free(to_add);
    to_add = my_int_to_str(nb_neuron);
    to_find = my_strcpy(to_find, to_add);
    to_find[my_strlen(to_find)] = '\0';
    free(to_add);
    index = find_index_array_hidden_wrd(presset, to_find);
    free(to_find);
    return (index);
}

float *sms_load_preset_weight(char **presset, int nb_layer, int nb_neuron)
{
    int index_start = get_index_line(presset, nb_layer, nb_neuron);
    float *weight = NULL;
    int nb_weight = 0;
    int index_end = 0;

    index_start++;
    index_end = index_start;
    if (presset == NULL || presset[0] == NULL
    || presset[0][0] == '\0' || index_start == 1)
        return (0);
    for (; presset[index_end] != NULL && ((presset[index_end][0] >= '0'
    && presset[index_end][0] <= '9')
    || presset[index_end][0] == '-'); index_end++, nb_weight++);

    weight = malloc(sizeof(float *) * nb_weight);
    if (weight == NULL)
        return (NULL);
    for (int i = 0; i < nb_weight; i++, index_start++) {
        weight[i] = my_str_to_float(presset[index_start]);
    }
    return (weight);
}

int sms_write_each_weight(float *weight, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        fs_write_float_debug_file(weight[i]);
        fs_write_debug_file(":", 0);
    }
}

int sms_write_eatch_nrn(layer_t *current_lay, model_t *model)
{
    neuron_t *nrn = NULL;
    int lgt = 0;
    int lr = model->learning_rate;

    for (int i = 0; i < current_lay->nb_neuron; i++) {
        nrn = sms_find_neuron_by_id(current_lay, i);
        if (nrn == NULL)
            return (ERROR);
        lgt = current_lay->lenght_prev_layer;
        fs_write_debug_file("\n:L", current_lay->id + 1);
        fs_write_debug_file("N", nrn->id + 1);
        if ( i + 1 <= current_lay->nb_neuron)
            fs_write_debug_file(":", 0);
        if (lgt == 0)
            lgt = model->nb_input;
        sms_write_each_weight(nrn->weight, lgt);
    }
    return (SUCCESS);
}

int write_log_file(model_t *model)
{
    layer_t *current_lay = NULL;

    if (model->ann_log == NULL)
        return (ERROR);
    if (remove("ANN_LOG") == 0) {
        fs_write_debug_file("NEED4STEK.", 0);
        // fs_write_debug_file("\nFIT:", lidar->fit);
        for (int i = 0; i < model->nb_layers; i++) {
            current_lay = sms_find_layer_by_id(model, i);
            if (current_lay == NULL
            || sms_write_eatch_nrn(current_lay, model) == ERROR)
                return (ERROR);
        }
        fs_write_debug_file("\n\tWritten by Samson lib.", 0);
    }
    return (SUCCESS);
}

int sms_match_ml_user_output(model_t *model)
{
    int retropropagation = FALSE;

    for (int i = 0; i < model->nb_output; i++) {
        model->gradient[i] = sms_compute_gradient(model->output_set[i], model->result_wanted[i]);
        if (model->gradient[i] > model->learning_rate) {
            model->loss++;
            retropropagation = TRUE;
        } else
            model->accuracy++;
    }
}

int sms_fit_model(model_t *model, char *activation, ann_trainer_t *ann_trainer)
{
    int max_gen = 123;

    if (sms_compile_model(model) == ERROR)
        return (ERROR);
    for (int count_gen = 0; count_gen < max_gen; count_gen++) {
        // my_error("turn ascii input_set\n");
        model->input_set = ascii_dataset_to_float_arr(ann_trainer->input_user, ann_trainer->nb_input, count_gen * ann_trainer->nb_input);
        // my_error("turn ascii output_set\n");
        model->result_wanted = ascii_dataset_to_float_arr(ann_trainer->output_user, 1, count_gen);
        // my_error("filling data\n");
        if (sms_fill_dataset_user(model, model->input_set, ann_trainer->nb_input) == ERROR)
            return (ERROR);
        // my_error("linking model\n");
        if (sms_link_model(model) == ERROR)
            return (ERROR);
        // my_error("displaying model\n");
        sms_display_model(model, count_gen + 1, max_gen);
        // my_error("printf\n");
        printf("model output = %f\n", model->output_set[0]);
        printf("user output = %f\n", model->result_wanted[0]);

        // my_error("before match and learn\n");
        if (sms_match_ml_user_output(model) == TRUE)
            sms_learn(model);
        // free(model->input_set);
        // free(model->output_set);
    }
    if (model->accuracy > 98)
        write_log_file(model);
    return (SUCCESS);
}