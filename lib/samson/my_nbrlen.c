/*
** EPITECH PROJECT, 2019
** my_nbrlen
** File description:
** my_nbrlen
*/

int my_nbrlen(int nbr)
{
    int i = 1;
    int tmp = 0;

    if (nbr < 10 && nbr >= 0)
        return (1);
    else {
        for (; nbr >= 10; i++) {
            tmp = nbr % 10;
            nbr = nbr - tmp;
            nbr = nbr / 10;
        }
    }
    return (i);
}