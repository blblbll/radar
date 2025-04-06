/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** str to word array
*/
#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_lenligne(char const *str)
{
    int cpt = 0;
    for (int i = 0; str[i] != '\n'; i++) {
        cpt++;
    }
    return cpt;
}

int lenmot(char const *str, int j)
{
    int cpt = 0;
    while (j < my_strlen(str) && str[j] != '\n') {
        j++;
        cpt++;
    }
    return cpt;
}

void getmot(char const *str, char **result, int e, int *j)
{
    int a = 0;
    for (*j; str[*j] != '\n'; *j = *j + 1) {
        result[e][a] = str[*j];
        a++;
    }
    result[e][a] = '\0';
    *j = *j + 1;
    return;
}

char **my_str_to_word_array(char const *str)
{
    int e = 0;
    char **result;
    int len_phrase = lentotal(str);
    int a = cptmot(str);
    result = malloc(sizeof(char *) * (len_phrase + 1));
    for (int i = 0; i < a; i++) {
        result[i] = malloc(sizeof(char) * my_strlen(str) + 1);
    }
    int j = 0;
    for (e; e < a - 1; e++) {
        getmot(str, result, e, &j);
    }
    result[e] = NULL;
    return result;
}
