/*
** EPITECH PROJECT, 2022
** avion.c
** File description:
** avion data
*/
#include "../include/my.h"

struct sfRectangleShape *create_hitbox(int xd, int yd)
{
    sfRectangleShape *rect;
    rect = sfRectangleShape_create();
    sfVector2f v;
    v.x = xd;
    v.y = yd;
    sfRectangleShape_setPosition(rect, v);
    v.x = 20.0;
    v.y = 20.0;
    sfRectangleShape_setSize(rect, v);
    sfRectangleShape_setFillColor (rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1.0);
    return rect;
}

struct avion str_to_avion(int *array)
{
    struct avion tmp;
    tmp.xd = array[0];
    tmp.xa = array[2];
    tmp.yd = array[1];
    tmp.ya = array[3];
    tmp.v = array[4];
    tmp.t = array[5];
    tmp.null = 0;
    tmp.alive = 1;
    tmp.texture = sfTexture_createFromFile("assets/avion.png", NULL);;
    tmp.sprite = sfSprite_create();
    sfSprite_setTexture(tmp.sprite, tmp.texture, sfTrue);
    tmp.hitbox = create_hitbox(tmp.xd, tmp.yd);
    tmp.vx = (tmp.xd > tmp.xa) ? -(tmp.v) : tmp.v;
    tmp.vy = (tmp.yd > tmp.ya) ? -(tmp.v) : tmp.v;
    tmp.onscreen = 0;
    return tmp;
}

struct avion get_avion(char *ligne)
{
    int *info = malloc(sizeof(int) * 6);
    int i = 0;
    int indice = 0;
    while (i < my_strlen(ligne)) {
        if (ligne[i] <= '9' && ligne[i] >= '0') {
            info[indice] = my_get_nbr_i(ligne, &i);
            indice++;
        }
        i++;
    }
    return str_to_avion(info);
}

int get_nb_avion(char **info)
{
    int cpta = 0;
    for (int i = 0; info[i] != NULL; i++)
        if (info[i][0] == 'A')
            cpta++;
    return cpta;
}

struct avion* get_list_avion(char **info)
{
    struct avion *list = malloc(sizeof(struct avion)
    * (get_nb_avion(info) + 1));
    int indice = 0;
    for (int i = 0; info[i] != NULL; i++) {
        if (info[i][0] == 'A') {
            list[indice] = get_avion(info[i]);
            indice++;
        }
    }
    struct avion avionnull;
    avionnull.null = 1;
    list[indice] = avionnull;
    return list;
}
