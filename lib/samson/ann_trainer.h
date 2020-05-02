/*
** EPITECH PROJECT, 2020
** n4s.h
** File description:
** This file contains all the prototypes that allow to build the prog.
*/

#ifndef MY_ANN_TRAINER_H
#define MY_ANN_TRAINER_H

typedef struct ann_trainer_s {
    char *ann_log_name;
    char *ann_input_name;
    char *ann_output_name;
    char **ann;
    char **input_user;
    char **output_user;
    char **output_ann;
    int nb_input;
} ann_trainer_t;

int brain(ann_trainer_t *ann_trainer);
float *ascii_dataset_to_float_arr(char **array, int lenght_wanted, int start);

#endif
