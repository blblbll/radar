/*
** EPITECH PROJECT, 2022
** lib2.c
** File description:
** lib functions for strlen
*/
#include "../include/my.h"

int cptmot(char const *str)
{
    int i = 0;
    int cpt = 0;
    for (i; str[i] != '\0'; i++) {
        if (str[i + 1] == '\n' || str[i + 1] == '\0')
            cpt++;
    }
    return cpt;
}

int lentotal(char const *str)
{
    int i = 0;
    int cpt = 0;
    for (i; str[i] != '\0'; i++) {
        if (str[i] != '\n')
            cpt++;
    }
    return cpt;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
