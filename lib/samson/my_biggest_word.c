/*
** EPITECH PROJECT, 2020
** my_biggest_word.c
** File description:
** This file contains a function that take a buffer,
** and a char and count,
** the biggest string contain into
**  the buffer separate by a semi colon, a space or
** the char name stop take as parameter.
*/

int my_biggest_word_into_buff(char *buff, char stop)
{
    int n = 0;
    int biggest = 0;

    for (int i = 0; buff[i] != '\0'; i++, n++) {
        if (buff[i] == stop && n > biggest) {
            n--;
            biggest = n;
            n = 0;
        } else if (buff[i] == stop)
            n = 0;
    }
    n--;
    if (n > biggest)
        return (n);
    return (biggest);
}