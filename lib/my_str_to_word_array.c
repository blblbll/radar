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

    while (str[i] != '\0')
        i++;
    return (i);
}

static int line_len(char const *str)
{
    int len = 0;

    while (str[len] != '\0' && str[len] != '\n')
        len++;
    if (len > 0 && str[len - 1] == '\r')
        len--;
    return len;
}

static int is_blank(char const *str, int len)
{
    for (int i = 0; i < len; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return 0;
    return 1;
}

static int count_lines(char const *str)
{
    int count = 0;
    int len = 0;

    while (*str != '\0') {
        len = line_len(str);
        if (!is_blank(str, len))
            count++;
        while (*str != '\0' && *str != '\n')
            str++;
        if (*str == '\n')
            str++;
    }
    return count;
}

static char *copy_line(char const *str, int len)
{
    char *line = malloc(sizeof(char) * (len + 1));

    if (line == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        line[i] = str[i];
    line[len] = '\0';
    return line;
}

char **my_str_to_word_array(char const *str)
{
    char **result = malloc(sizeof(char *) * (count_lines(str) + 1));
    int e = 0;
    int len = 0;

    if (result == NULL)
        return NULL;
    while (*str != '\0') {
        len = line_len(str);
        if (!is_blank(str, len))
            result[e++] = copy_line(str, len);
        while (*str != '\0' && *str != '\n')
            str++;
        if (*str == '\n')
            str++;
    }
    result[e] = NULL;
    return result;
}
