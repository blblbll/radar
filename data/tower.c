/*
** EPITECH PROJECT, 2022
** tower.c
** File description:
** tower data
*/
#include "../include/my.h"

static sfTexture *g_texture = NULL;

void free_tower_texture(void)
{
    if (g_texture != NULL)
        sfTexture_destroy(g_texture);
    g_texture = NULL;
}

sfCircleShape *get_hitbox(struct tower tmp)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f vector;

    vector.x = tmp.x - tmp.r;
    vector.y = tmp.y - tmp.r;
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
    sfVector2f vector;

    tmp.x = array[0];
    tmp.y = array[1];
    tmp.r = array[2];
    tmp.null = 0;
    if (g_texture == NULL)
        g_texture = sfTexture_createFromFile("assets/tower.png", NULL);
    tmp.texture = g_texture;
    tmp.sprite = sfSprite_create();
    if (tmp.texture != NULL)
        sfSprite_setTexture(tmp.sprite, tmp.texture, sfTrue);
    vector.x = tmp.x - TOWER_SIZE / 2;
    vector.y = tmp.y - TOWER_SIZE / 2;
    sfSprite_setPosition(tmp.sprite, vector);
    tmp.zone = get_hitbox(tmp);
    return tmp;
}

struct tower get_tower(char *ligne)
{
    int info[3] = {0, 0, 0};
    int i = 0;
    int indice = 0;

    while (ligne[i] != '\0' && indice < 3) {
        if (ligne[i] <= '9' && ligne[i] >= '0') {
            info[indice] = my_get_nbr_i(ligne, &i);
            indice++;
        } else
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

    if (list == NULL)
        return NULL;
    for (int i = 0; info[i] != NULL; i++) {
        if (info[i][0] == 'T') {
            list[indice] = get_tower(info[i]);
            indice++;
        }
    }
    list[indice].null = 1;
    return list;
}
