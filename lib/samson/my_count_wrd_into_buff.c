/*
** EPITECH PROJECT, 2020
** my_count_wrd_into_buff.c
** File description:
** This file contains a function that
** take a string in parameter and a char.
** And count the number of time the string is cut by the char.
*/

int my_count_wrd_into_buff(char *str, char stop)
{
    int word = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == stop)
            word += 1;
    }
    return (word);
}