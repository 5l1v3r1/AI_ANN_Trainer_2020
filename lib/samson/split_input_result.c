/*
** EPITECH PROJECT, 2020
** split_input_result.c
** File description:
** This file contains a function that split the dataset into input and
** result set.
** Prototype : char **sms_split_input_result(char **dataset, char **resultset,
** index_re)
** Parameters : char **dataset, char **resultset;
** Return value : char **result; result[i] can contains only 0 or 1.
** Tips/Info : the index_res is the index of result into dataset
*/

// #include "samson.h"

// char **prepare_resultset(char **result, int nb_str)
// {
//     result = malloc(sizeof(char *) * (nb_str + 1));
//     if (result == NULL)
//         return (NULL);
//     for (int i = 0; i < nb_str; i++) {
//         result[i] = NULL;
//         result[i] = malloc(sizeof(char) * 2);
//         if (result[i] == NULL)
//             return (NULL);
//         result[i][0] = 0;
//         result[i][1] = 0;
//     }
//     return (result);
// }

// char *get_result(char *datastr, char *resultstr, int index_res)
// {
//     for (int i = 0; datastr[i] != '\0'; i++) {
//         if (i == index_res) {
//             resultstr[i] = datastr[i];
//             datastr[i] = 0;
//         }
//     }
//     return (resultstr);
// }

// char **sms_split_input_result(char **dataset, char **resultset, int index_res)
// {
//     int nb_str = 0;

//     if (dataset == NULL)
//         return (NULL);
//     for (nb_str; dataset[nb_str] != NULL; nb_str++);
//     resultset = prepare_resultset(resultset, nb_str);
//     for (int i = 0; dataset[i] != NULL; i++) {
//         if (i == index_res) {
//             resultset[i][0] = dataset[i][0];
//             datastr[i] = 0;
//         }
//     }
//         resultset[i] = get_result(dataset[i], resultset[i], index_res);
//     return (resultset);
// }