/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error handling
*/
#include "./include/my.h"

static int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

static int count_numbers(char const *line)
{
    int i = 1;
    int count = 0;

    if (!is_space(line[i]))
        return -1;
    while (line[i] != '\0') {
        while (is_space(line[i]))
            i++;
        if (line[i] == '\0')
            break;
        if (line[i] < '0' || line[i] > '9')
            return -1;
        while (line[i] >= '0' && line[i] <= '9')
            i++;
        if (line[i] != '\0' && !is_space(line[i]))
            return -1;
        count++;
    }
    return count;
}

static int verif_line(char **liste, int j)
{
    char type = liste[j][0];

    if (type == 'A')
        return (count_numbers(liste[j]) == 6) ? 0 : 84;
    if (type == 'T')
        return (count_numbers(liste[j]) == 3) ? 0 : 84;
    return 84;
}

int error_lines(char **liste)
{
    for (int j = 0; liste[j] != NULL; j++) {
        if (verif_line(liste, j) == 84) {
            my_puterr("invalid data\n");
            return 84;
        }
    }
    return 0;
}
