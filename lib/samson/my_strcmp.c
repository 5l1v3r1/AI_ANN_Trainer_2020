/*
** EPITECH PROJECT, 2019
** task06_my_strcmp
** File description:
** compare the lenth of two string
*/

int my_strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == s2[i] && s1[i] == '\0')
            return (1);
        else if (!s1[i] || !s2[i])
            return (0);
    }
}