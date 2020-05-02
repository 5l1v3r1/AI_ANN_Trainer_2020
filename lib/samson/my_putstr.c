/*
** EPITECH PROJECT, 2019
** task02_my_putstr
** File description:
** write a sting on the terminal
*/

#include "samson.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}