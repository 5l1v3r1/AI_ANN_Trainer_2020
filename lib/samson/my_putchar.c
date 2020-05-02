/*
** EPITECH PROJECT, 2019
** task00_my_putchar
** File description:
** write a char on the terminal
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
