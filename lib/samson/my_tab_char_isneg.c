/*
** EPITECH PROJECT, 2019
** my_tab_char_isneg.c
** File description:
** This function return (0) if the string is positive
** This function return (1) if the strin is negative
*/

int my_tab_char_isneg(char *src)
{
    int result = 0;

    if (src[0] == '-') {
        result = 1;
    }
    return (result);
}