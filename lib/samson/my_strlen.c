/*
** EPITECH PROJECT, 2019
** task_03_my_strlen
** File description:
** count the lenth of the string
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}