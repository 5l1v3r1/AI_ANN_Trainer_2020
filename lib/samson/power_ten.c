/*
** EPITECH PROJECT, 2020
** power_ten.c
** File description:
** This file contains a function that calcul the power n of ten of a number.
** Params : float number, float xposant.
** Return : float.
*/

float sms_xposant_ten(float number, int xposant)
{
    int factor = 1;
    int absolut = xposant;

    if (absolut < 0)
        absolut *= -1;
    for (int i = 0; i < absolut; i++)
        factor *= 10;
    if (xposant < 0)
        number /= factor;
    else
        number *= factor;
    return (number);
}