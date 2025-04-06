/*
** EPITECH PROJECT, 2022
** openf
** File description:
** open a file and get it in a char *
*/
#include "../include/my.h"

char *fs_open_file(const char *pathfile)
{
    struct stat stati;
    char *buff;
    int fd = open(pathfile, O_RDONLY);
    if (fd < 0) {
        write(2, "file cannot be read", 19);
        return NULL;
    }
    stat(pathfile, &stati);
    int taille = stati.st_size;
    buff = malloc(sizeof(char) * (taille + 2));
    read(fd, buff, taille);
    buff[taille] = '\0';
    return (buff);
}
