/*
** EPITECH PROJECT, 2020
** samson.h
** File description:
** This file contains all the prototypes needed to use Samson library.
*/

#ifndef SAMSON_H
#define SAMSON_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ann_trainer.h"

typedef struct neuron_s {
    int id;
    float som;
    float prob;//chager par activate ou activation
    float *weight;
    struct neuron_s *next;
} neuron_t;

typedef struct layer_s {
    int id;
    int nb_neuron;
    int lenght_prev_layer;
    neuron_t *first;
    struct layer_s *next;
} layer_t;

typedef struct model_s {
    float *gradient;
    float loss;
    float accuracy;
    float biais;
    float learning_rate;
    int nb_input;
    int nb_output;
    int nb_layers;
    float *input_set;
    char **ann_log;
    float *output_set;
    float *result_wanted;
    struct layer_s *first;
} model_t;

                                                                         //start CONST AND DEFINE
#define TRUE          1                                                        //CONST AND DEFINE
#define FALSE         0                                                        //CONST AND DEFINE
#define EXP           2.718281828459045                                        //CONST AND DEFINE
#define EULER         2.718281                                                 //CONST AND DEFINE
#define MAX_FLOAT 10000000000000000000000000000000000000                       //CONST AND DEFINE
#define LEARNING_RATE 0.3                                                      //CONST AND DEFINE
#define ERROR         84                                                       //CONST AND DEFINE
#define SUCCESS       0                                                        //CONST AND DEFINE
#define READ_SIZE     1                                                        //CONST AND DEFINE
#define TOTAL_NRN 122                                                          //CONST AND DEFINE
#define PERCENT_MUTATION 20                                                    //CONST AND DEFINE
#define TO_MUT_NRN ((PERCENT_MUTATION / TOTAL_NRN) * 100)                      //CONST AND DEFINE
                                                                           //end CONST AND DEFINE

                                                                         //start PROTOTYPES LIB MY
void my_putchar(char c);                                                       //PROTOTYPES LIB MY
int my_isneg(int nb);                                                          //PROTOTYPES LIB MY
int my_put_nbr(int nb);                                                        //PROTOTYPES LIB MY
void my_swap(int *a, int *b);                                                  //PROTOTYPES LIB MY
void my_putstr(char const *str);                                               //PROTOTYPES LIB MY
int my_strlen(char const *str);                                                //PROTOTYPES LIB MY
int my_getnbr(char const *str);                                                //PROTOTYPES LIB MY
void my_sort_int_array(int *tab, int size);                                    //PROTOTYPES LIB MY
int my_compute_power_rec( int nb, int power);                                  //PROTOTYPES LIB MY
int my_compute_square_root(int nb);                                            //PROTOTYPES LIB MY
int my_is_prime(int nb);                                                       //PROTOTYPES LIB MY
int my_find_prime_sup(int nb);                                                 //PROTOTYPES LIB MY
char *my_strcpy(char *dest, char const *src);                                  //PROTOTYPES LIB MY
char *my_strncpy(char *dest, char const *src, int n);                          //PROTOTYPES LIB MY
char *my_revstr(char *str);                                                    //PROTOTYPES LIB MY
int matching(char *str, char const *to_find, int i);                           //PROTOTYPES LIB MY
char *my_strstr(char *str, char const *to_find);                               //PROTOTYPES LIB MY
int my_strcmp(char const *s1, char const *s2);                                 //PROTOTYPES LIB MY
int my_strncmp(char const *s1, char const *s2, int n);                         //PROTOTYPES LIB MY
char *my_strupcase(char *str);                                                 //PROTOTYPES LIB MY
char *my_strlowcase(char *str);                                                //PROTOTYPES LIB MY
char *my_strcapitalize(char *str);                                             //PROTOTYPES LIB MY
int my_str_isalpha(char const *str);                                           //PROTOTYPES LIB MY
int my_str_isnum(char const *str);                                             //PROTOTYPES LIB MY
int my_str_islower(char const *str);                                           //PROTOTYPES LIB MY
int my_str_isupper(char const *str);                                           //PROTOTYPES LIB MY
int my_str_isprintable(char const *str);                                       //PROTOTYPES LIB MY
int my_showstr(char const *str);                                               //PROTOTYPES LIB MY
int my_showmem(char const *str, int size);                                     //PROTOTYPES LIB MY
char *my_strcat(char *dest, char *src);                                        //PROTOTYPES LIB MY
char *my_strncat(char *dest, char const *src, int nb);                         //PROTOTYPES LIB MY
int *my_mallocer_int(int lenth_wanted);                                        //PROTOTYPES LIB MY
char *my_mallocer_char(int lenth_wanted);                                      //PROTOTYPES LIB MY
int my_tab_char_isneg(char *src);                                              //PROTOTYPES LIB MY
int my_transform_char_into_digit(char nb);                                     //PROTOTYPES LIB MY
int my_str_to_digit(char *str);                                                //PROTOTYPES LIB MY
char *my_int_to_str(int nb);                                                   //PROTOTYPES LIB MY
int my_nbrlen(int nbr);                                                        //PROTOTYPES LIB MY
char *my_strdup(char *str);                                                    //PROTOTYPES LIB MY
int my_error(const char *str);                                                 //PROTOTYPES LIB MY
int my_put_unsint(unsigned int number);                                        //PROTOTYPES LIB MY
int my_put_double(char *str);                                                  //PROTOTYPES LIB MY
double my_transform_char_into_double(char *str);                               //PROTOTYPES LIB MY
void tab_of_point_on_func(int (*tab_point[])(char *));                         //PROTOTYPES LIB MY
char **my_str_to_word_array(char *str, int slash_mode_on);                     //PROTOTYPES LIB MY
int my_biggest_word_into_buff(char *buff, char stop);                          //PROTOTYPES LIB MY
char **my_file_to_dbl_array(char *filename, char parser);                      //PROTOTYPES LIB MY
int my_count_wrd_into_buff(char *str, char stop);                              //PROTOTYPES LIB MY
                                                                           //end PROTOTYPES LIB MY

                                                                         //start PROTOTYPES LIB MY_FS
void fs_cat_x_bytes(char const *filepath, int x);                              //PROTOTYPES LIB MY_FS
int fs_get_number_from_first_line(int fd);                                     //PROTOTYPES LIB MY_FS
int fs_open_file(char const *filepath);                                        //PROTOTYPES LIB MY_FS
void fs_print_first_line(char const *filepath);                                //PROTOTYPES LIB MY_FS
int fs_understand_return_of_read(int fd, char *buffer, int size);              //PROTOTYPES LIB MY_FS
int fs_nb_char_into_file(char *file_name);                                     //PROTOTYPES LIB MY_FS
int fs_write_debug_file(char *str_to_write, int nb_to_write);                  //PROTOTYPES LIB MY_FS
                                                                           //end PROTOTYPES LIB MY_FS

                                                                         //start PROTOTYPES LIB SAMSON
int sms_random_gen_int(int min, int max);                                      //PROTOTYPES LIB SAMSON
float sms_random_float(float min, float max, int nb_dec);                      //PROTOTYPES LIB SAMSON
float sms_xposant_ten(float number, int xposant);                              //PROTOTYPES LIB SAMSON
char **sms_open_csv(char *filename);                                           //PROTOTYPES LIB SAMSON
float sms_exp(float nb);                                                       //PROTOTYPES LIB SAMSON
char **sms_int_encoder(char **dataset);                                        //PROTOTYPES LIB SAMSON
char *sms_clean_array(char *str, int lenght);                                  //PROTOTYPES LIB SAMSON
char *sms_fit_lines(char *str, int lenght);                                    //PROTOTYPES LIB SAMSON
void sms_display_first_end_line(model_t *model, char *display_lines, int end); //PROTOTYPES LIB SAMSON
int sms_add_neuron(layer_t *layer, int id, int lenght_prev_lay, char **presset); //PROTOTYPES LIB SAMSON
neuron_t *sms_get_last_neuron(neuron_t *current);                              //PROTOTYPES LIB SAMSON
neuron_t *sms_prepare_new_neuron(neuron_t *new, int id);                       //PROTOTYPES LIB SAMSON
float *sms_clean_float_array(float *array, int lenght);                        //PROTOTYPES LIB SAMSON
int sms_rm_neuron(layer_t *layer);                                             //PROTOTYPES LIB SAMSON
int sms_add_layer(model_t *model, int nb_neuron);                              //PROTOTYPES LIB SAMSON
neuron_t *sms_find_neuron_by_id(layer_t *layer, int id);                       //PROTOTYPES LIB SAMSON
layer_t *sms_find_layer_by_id(model_t *model, int id);                         //PROTOTYPES LIB SAMSON
model_t *sms_init_model(int nb_input, int nb_output);                          //PROTOTYPES LIB SAMSON
int sms_rm_model(model_t *model);                                              //PROTOTYPES LIB SAMSON
void sms_print_layer_model(model_t *model);                                    //PROTOTYPES LIB SAMSON
void sms_print_neuron_layer(layer_t *layer);                                   //PROTOTYPES LIB SAMSON
int sms_fit_model(model_t *model, char *activation, ann_trainer_t *ann_trainer);
int sms_try_model(model_t *model);                                             //PROTOTYPES LIB SAMSON
int sms_try_layers(model_t *model, int nb_layers);                             //PROTOTYPES LIB SAMSON
int sms_try_neurons(model_t *model);                                           //PROTOTYPES LIB SAMSON
int sms_prepare_model(model_t *model, int nb_input, int nb_output);            //PROTOTYPES LIB SAMSON
int sms_compile_model(model_t *model);                                         //PROTOTYPES LIB SAMSON
float sms_somme(float som_nrn_lay2, float prob_nrn_lay1, float wgth_nrn_lay2); //PROTOTYPES LIB SAMSON
float sms_activation(float som);                                               //PROTOTYPES LIB SAMSON
int sms_link_model(model_t *model);                                            //PROTOTYPES LIB SAMSON
int sms_layer_lenght(layer_t *layer);                                          //PROTOTYPES LIB SAMSON
int sms_fill_dataset_user(model_t *model, float *user_dtset, int lenght_u);    //PROTOTYPES LIB SAMSON
float sms_get_proba_into_neuron(layer_t *layer, int id);                       //PROTOTYPES LIB SAMSON
int sms_fill_dataoutput_mlresult(model_t *model);                              //PROTOTYPES LIB SAMSON
int proces_link_nrn(layer_t *layer1, neuron_t *nrn_lay2);                      //PROTOTYPES LIB SAMSON
int sms_link_two_neuron_together(layer_t *layer1, neuron_t *nrn2, int n);      //PROTOTYPES LIB SAMSON
float sms_compute_gradient(float ml_activate, float result_activate);
int sms_display_model(model_t *model, int cur_gen, int tot_gen);
float *retropropagation(float *array, int lenght, float gradient, float lr);
void sms_free_csv(char **data);
void sms_display_csv(char **data);
char *get_next_line(int fd);
int hidenp(char *to_find, char *stack);
int find_index_array_hidden_wrd(char **presset, char *to_find);
float my_str_to_float(char *str_num);
char *my_float_to_str(float nb);
int fs_write_float_debug_file(float nb_to_write);
float *sms_load_preset_weight(char **presset, int nb_layer, int nb_neuron);
int sms_add_mutation_spec_nrn(model_t *model, int id_lay, int id_nrn, int perc);
int sms_ajust_weights(float *array, int lenght, float ajustement);
int sms_decrease_nrn_strength(model_t *model, int id_nrn);
int sms_increase_nrn_strength(model_t *model, int id_nrn);
int sms_rl_backpropagation(model_t *model, int guilty_nrn);
// char **sms_split_input_result(char **dataset, char **resultset, int index_res);
                                                                           //end PROTOTYPES LIB SAMSON

#endif