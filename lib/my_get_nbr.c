/*
** EPITECH PROJECT, 2022
** my_get_nbr
** File description:
** transform a nbr string into int
*/
//#include <stddef.h>
#include "../include/my.h"

int my_get_nbr(char *str)
{
    int i = 0;
    int cptm = 0;
    int result = 0;
    for (i; str[i] != '\0'; i++) {
        if (str[i] != '+' && str[i] != '-')
            break;
        if (str[i] == '-')
            cptm++;
    }
    for (i; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        result = result * 10;
        result = result + (str[i] - 48);
    }
    if (result < 0)
        return 0;
    if (cptm % 2 == 1)
        result = result * -1;
    return result;
}

int my_get_nbr_i(char *str, int *i)
{
    int cptm = 0;
    int result = 0;
    for (*i; str[*i] != '\0'; *i = *i + 1) {
        if (str[*i] != '+' && str[*i] != '-')
            break;
        if (str[*i] == '-')
            cptm++;
    }
    for (*i; str[*i] != '\0'; *i = *i + 1) {
        if (str[*i] < '0' || str[*i] > '9')
            break;
        result = result * 10;
        result = result + (str[*i] - 48);
    }
    if (result < 0)
        return 0;
    if (cptm % 2 == 1)
        result = result * -1;
    return result;
}
