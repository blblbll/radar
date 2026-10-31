/*
** EPITECH PROJECT, 2022
** avion.c
** File description:
** avion data
*/
#include "../include/my.h"

static sfTexture *g_texture = NULL;

void free_avion_texture(void)
{
    if (g_texture != NULL)
        sfTexture_destroy(g_texture);
    g_texture = NULL;
}

sfRectangleShape *create_hitbox(float xd, float yd)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f v;

    v.x = xd - PLANE_SIZE / 2;
    v.y = yd - PLANE_SIZE / 2;
    sfRectangleShape_setPosition(rect, v);
    v.x = PLANE_SIZE;
    v.y = PLANE_SIZE;
    sfRectangleShape_setSize(rect, v);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1.0);
    return rect;
}

struct avion str_to_avion(int *array)
{
    struct avion tmp;

    tmp.xd = array[0];
    tmp.yd = array[1];
    tmp.xa = array[2];
    tmp.ya = array[3];
    tmp.v = array[4];
    tmp.t = array[5];
    tmp.null = 0;
    tmp.alive = 1;
    tmp.onscreen = 0;
    if (g_texture == NULL)
        g_texture = sfTexture_createFromFile("assets/avion.png", NULL);
    tmp.texture = g_texture;
    tmp.sprite = sfSprite_create();
    if (tmp.texture != NULL)
        sfSprite_setTexture(tmp.sprite, tmp.texture, sfTrue);
    tmp.hitbox = create_hitbox(tmp.xd, tmp.yd);
    return tmp;
}

struct avion get_avion(char *ligne)
{
    int info[6] = {0, 0, 0, 0, 0, 0};
    int i = 0;
    int indice = 0;

    while (ligne[i] != '\0' && indice < 6) {
        if (ligne[i] <= '9' && ligne[i] >= '0') {
            info[indice] = my_get_nbr_i(ligne, &i);
            indice++;
        } else
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

    if (list == NULL)
        return NULL;
    for (int i = 0; info[i] != NULL; i++) {
        if (info[i][0] == 'A') {
            list[indice] = get_avion(info[i]);
            indice++;
        }
    }
    list[indice].null = 1;
    return list;
}
