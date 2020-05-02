/*
** EPITECH PROJECT, 2019
** task03_my_revstr
** File description:
** reverse a string and returns the same string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int n = 0;
    char tempo = 'a';

    while (str[i] != '\0')
        i++;
    for (int m = i; m != i/2; m--) {
        tempo = str[m-1];
        str[m-1] = str[n];
        str[n] = tempo;
        n++;
    }
    return (str);
}