/*
** EPITECH PROJECT, 2022
** tower.c
** File description:
** tower data
*/
#include "../include/my.h"

sfCircleShape *get_hitbox(struct tower tmp, sfVector2f vector)
{
    sfCircleShape *circle = sfCircleShape_create();
    vector.x = vector.x + 25 - tmp.r;
    vector.y = vector.y + 25 - tmp.r;
    sfCircleShape_setPosition(circle, vector);
    sfCircleShape_setRadius(circle, tmp.r);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 1.0);
    return circle;
}

struct tower str_to_tower(int *array)
{
    struct tower tmp;
    tmp.x = array[0];
    tmp.y = array[1];
    tmp.r = array[2];
    tmp.null = 0;
    tmp.texture = sfTexture_createFromFile("assets/tower.png", NULL);;
    tmp.sprite = sfSprite_create();
    sfSprite_setTexture(tmp.sprite, tmp.texture, sfTrue);
    sfVector2f vector;
    vector.x = tmp.x;
    vector.y = tmp.y;
    sfSprite_setPosition(tmp.sprite, vector);
    tmp.zone = get_hitbox(tmp, vector);
    return tmp;
}

struct tower get_tower(char *ligne)
{
    int *info = malloc(sizeof(int) * 3);
    int i = 0;
    int indice = 0;
    while (i < my_strlen(ligne)) {
        if (ligne[i] <= '9' && ligne[i] >= '0') {
            info[indice] = my_get_nbr_i(ligne, &i);
            indice++;
        }
        i++;
    }
    return str_to_tower(info);
}

int get_nb_tower(char **info)
{
    int cpta = 0;
    for (int i = 0; info[i] != NULL; i++)
        if (info[i][0] == 'T')
            cpta++;
    return cpta;
}

struct tower* get_list_tower(char **info)
{
    struct tower *list = malloc(sizeof(struct tower)
    * (get_nb_tower(info) + 1));
    int indice = 0;
    for (int i = 0; info[i] != NULL; i++) {
        if (info[i][0] == 'T') {
            list[indice] = get_tower(info[i]);
            indice++;
        }
    }
    struct tower towernull;
    towernull.null = 1;
    list[indice] = towernull;
    return list;
}
