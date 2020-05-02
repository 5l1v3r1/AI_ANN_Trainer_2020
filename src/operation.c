/*
** EPITECH PROJECT, 2020
** operation.c
** File description:
** This file contains a part of all operation that can be exec.
*/

#include "samson.h"

int fail(char *status)
{
    if (status[0] == '1' && status[1] == ':')
        return (SUCCESS);
    return (ERROR);
}


int stop_sim(void)
{
    char *response = NULL;

    my_putstr("stop_simulation\n");
    response = get_next_line(0);
    if (response != NULL && fail(response) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int start_sim(void)
{
    char *response = NULL;

    my_putstr("start_simulation\n");
    response = get_next_line(0);
    if (response != NULL && fail(response) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

char *get_car_stat(void)
{
    char *response = NULL;

    my_putstr("get_info_lidar\n");
    response = get_next_line(0);
    if (response == NULL && fail(response) == ERROR)
        return (NULL);
    return (response);
}