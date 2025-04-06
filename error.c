/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error handling
*/
#include "./include/my.h"

int verif_line_avion(char **liste, int j)
{
    int cptnb = 0;
    for (int i = 0; liste[j][i] != '\0'; i++)
        if (liste[j][i] == ' ' && (liste[j][i + 1] >= '0'
        && liste[j][i + 1] <= '9'))
            cptnb++;

    if (cptnb != 6)
        return 84;
    return 0;
}

int verif_line_tower(char **liste, int j)
{
    int cptnb = 0;
    for (int i = 0; liste[j][i] != '\0'; i++)
        if (liste[j][i] == ' ' && (liste[j][i + 1] >= '0'
        && liste[j][i + 1] <= '9'))
            cptnb++;

    if (cptnb != 3)
        return 84;
    return 0;
}

int error_lines(char **liste)
{
    for (int j = 0; liste[j] != NULL; j++) {
        if (liste[j][0] != 'A' && liste[j][0] != 'T') {
            write(2, "invalid dataa", 13);
            return 84;
        }
        if (liste[j][0] == 'A' && verif_line_avion(liste, j) == 84) {
            write(2, "invalid data", 12);
            return 84;
        }
        if (liste[j][0] == 'T' && verif_line_tower(liste, j) == 84) {
            write(2, "invalid data", 12);
            return 84;
        }
    }
    return 0;
}
