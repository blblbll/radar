/*
** EPITECH PROJECT, 2022
** my_get_nbr
** File description:
** transform a nbr string into int
*/
#include "../include/my.h"

int my_get_nbr_i(char *str, int *i)
{
    int cptm = 0;
    int result = 0;

    for (; str[*i] != '\0'; *i = *i + 1) {
        if (str[*i] != '+' && str[*i] != '-')
            break;
        if (str[*i] == '-')
            cptm++;
    }
    for (; str[*i] != '\0'; *i = *i + 1) {
        if (str[*i] < '0' || str[*i] > '9')
            break;
        result = result * 10;
        result = result + (str[*i] - 48);
    }
    if (cptm % 2 == 1)
        result = result * -1;
    return result;
}
