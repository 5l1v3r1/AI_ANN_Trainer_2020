/*
** EPITECH PROJECT, 2019
** task04_my_swap
** File description:
** swap the content of a int into an other
*/

void my_swap(int *a, int *b)
{
    int memory;

    memory = *a;
    *a = *b;
    *b = memory;
}