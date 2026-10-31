/*
** EPITECH PROJECT, 2022
** openf
** File description:
** open a file and get it in a char *
*/
#include "../include/my.h"

static char *read_all(int fd, long size)
{
    char *buff = malloc(sizeof(char) * (size + 1));
    long total = 0;
    long n = 0;

    if (buff == NULL)
        return NULL;
    while (total < size) {
        n = read(fd, buff + total, size - total);
        if (n <= 0)
            break;
        total += n;
    }
    buff[total] = '\0';
    if (n < 0) {
        free(buff);
        return NULL;
    }
    return buff;
}

char *fs_open_file(const char *pathfile)
{
    struct stat stati;
    char *buff;
    int fd;

    if (stat(pathfile, &stati) == -1 || !S_ISREG(stati.st_mode)) {
        my_puterr("file cannot be read\n");
        return NULL;
    }
    fd = open(pathfile, O_RDONLY);
    if (fd < 0) {
        my_puterr("file cannot be read\n");
        return NULL;
    }
    buff = read_all(fd, stati.st_size);
    close(fd);
    if (buff == NULL)
        my_puterr("file cannot be read\n");
    return buff;
}
