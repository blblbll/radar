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
    for (; str[i] != '\0'; i++) {
        if (str[i + 1] == '\n' || str[i + 1] == '\0')
            cpt++;
    }
    return cpt;
}

int lentotal(char const *str)
{
    int i = 0;
    int cpt = 0;
    for (; str[i] != '\0'; i++) {
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

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}

void my_int_to_str(int nb, char *buf)
{
    int len = 0;
    int tmp = nb;

    if (nb <= 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }
    while (tmp > 0) {
        len++;
        tmp /= 10;
    }
    buf[len] = '\0';
    while (nb > 0) {
        buf[--len] = nb % 10 + '0';
        nb /= 10;
    }
}
