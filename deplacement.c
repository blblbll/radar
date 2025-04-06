/*
** EPITECH PROJECT, 2023
** deplacement.c
** File description:
** deplacement
*/
#include "./include/my.h"

void set_pos(struct avion *av)
{
    sfVector2f v;
    v.x = av->xd;
    v.y = av->yd;
    sfSprite_setPosition(av->sprite, v);
    sfRectangleShape_setPosition(av->hitbox, v);
}

void destroyspri(struct avion *av)
{
    sfSprite_destroy(av->sprite);
    av->onscreen = 0;
    av->alive = 0;
}

void verif_arrive(struct avion *av)
{
    if (av->vx > 0 && av->vy > 0)
        if (av->xd >= av->xa && av->yd >= av->ya)
            destroyspri(av);
    if (av->vx < 0 && av->vy < 0)
        if (av->xd <= av->xa && av->yd <= av->ya)
            destroyspri(av);
    if (av->vx < 0 && av->vy > 0)
        if (av->xd <= av->xa && av->yd >= av->ya)
            destroyspri(av);
    if (av->vx > 0 && av->vy < 0)
        if (av->xd >= av->xa && av->yd <= av->ya)
            destroyspri(av);
}

void deplacerun(struct avion *av)
{
    if (av->vx > 0) {
        if (av->xd < av->xa)
            av->xd = av->xd + av->vx;
    }
    if (av->vx < 0){
        if (av->xd > av->xa)
            av->xd = av->xd + av->vx;
    }
    if (av->vy > 0) {
        if (av->yd < av->ya)
            av->yd = av->yd + av->vy;
    }
    if (av->vy < 0){
        if (av->yd > av->ya)
            av->yd = av->yd + av->vy;
    }
    set_pos(av);
    verif_arrive(av);
}

void deplacer(struct avion *listav)
{
    for (int i = 0; listav[i].null != 1; i++) {
        if (listav[i].alive == 1 && listav[i].onscreen == 1) {
            deplacerun(&listav[i]);
        }
    }
}
