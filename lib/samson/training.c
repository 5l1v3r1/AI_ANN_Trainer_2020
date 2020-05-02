/*
** EPITECH PROJECT, 2020
** training.c
** File description:
** This file contains all the function that print the training.
*/

#include "samson.h"

char *sms_fit_lines(char *str, int lenght)
{
    for (int i = 0; i < lenght; i++)
        str[i] = '=';
    return (str);
}

void display_data(model_t *model, int gen, int gen_tot)
{
    char *gen_str = my_int_to_str(gen);
    char *gentot_str = my_int_to_str(gen_tot);
    char *acc = my_int_to_str((model->accuracy / gen_tot) * 100);
    char *loss = my_int_to_str((model->loss / gen_tot) * 100);

    my_error("|Samson\t Generation : ");
    my_error(gen_str);
    my_error(" / ");
    my_error(gentot_str);
    my_error(", Accuracy : ");
    my_error(acc);
    my_error("%, Loss : ");
    my_error(loss);
    my_putstr(" %|\n");
    free(gen_str);
    free(gentot_str);
    free(acc);
    free(loss);
}

void sms_display_first_end_line(model_t *model, char *display_lines, int end)
{
    if (end == FALSE) {
        my_error(display_lines);
        my_error("SAMSON_START_TRAINING");
        my_putstr(display_lines);
        my_error("\n");
    } else {
        my_error(display_lines);
        my_error("=SAMSON_END_TRAINING=");
        my_error(display_lines);
        my_error("\n");
    }
}

int sms_display_model(model_t *model, int cur_gen, int tot_gen)
{
    int gen_lenght = my_nbrlen(tot_gen) + 60;
    char *display_lines = NULL;
    int nb_eq_disp = (gen_lenght - 21) / 2;

    if (nb_eq_disp <= 0)
        return (ERROR);
    display_lines = malloc(sizeof(char) * (nb_eq_disp + 1));
    if (display_lines == NULL)
        return (ERROR);
    display_lines = sms_clean_array(display_lines, nb_eq_disp + 1);
    display_lines = sms_fit_lines(display_lines, nb_eq_disp);
    if (display_lines == NULL)
        return (ERROR);
    if (cur_gen == 1)
        sms_display_first_end_line(model, display_lines, FALSE);
    display_data(model, cur_gen, tot_gen);
    if (cur_gen == tot_gen)
        sms_display_first_end_line(model, display_lines, TRUE);
    free(display_lines);
    return (SUCCESS);
}