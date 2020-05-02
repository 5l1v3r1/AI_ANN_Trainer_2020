/*
** EPITECH PROJECT, 2019
** task02_my_strncpy
** File description:
** copy a number of character into another string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int ex = 0;
    int i = 0;
    int a = 0;

    for (; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (;i < n;i++)
    {
        dest[i] = '\0';
    }
    return (dest);
}