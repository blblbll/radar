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

    v.x = av->xd - PLANE_SIZE / 2;
    v.y = av->yd - PLANE_SIZE / 2;
    sfSprite_setPosition(av->sprite, v);
    sfRectangleShape_setPosition(av->hitbox, v);
}

void destroyspri(struct avion *av)
{
    sfSprite_destroy(av->sprite);
    sfRectangleShape_destroy(av->hitbox);
    av->sprite = NULL;
    av->hitbox = NULL;
    av->onscreen = 0;
    av->alive = 0;
}

void takeoff(struct avion *listav, float sec)
{
    for (int i = 0; listav[i].null != 1; i++) {
        if (listav[i].alive == 1 && listav[i].onscreen == 0 &&
            sec >= listav[i].t) {
            listav[i].onscreen = 1;
            set_pos(&listav[i]);
        }
    }
}

static void deplacerun(struct avion *av, float dt)
{
    float dx = av->xa - av->xd;
    float dy = av->ya - av->yd;
    float dist = sqrtf(dx * dx + dy * dy);
    float step = av->v * dt;

    if (dist <= step) {
        av->xd = av->xa;
        av->yd = av->ya;
        destroyspri(av);
        return;
    }
    av->xd = av->xd + dx / dist * step;
    av->yd = av->yd + dy / dist * step;
    set_pos(av);
}

void deplacer(struct avion *listav, float dt)
{
    for (int i = 0; listav[i].null != 1; i++) {
        if (listav[i].alive == 1 && listav[i].onscreen == 1) {
            deplacerun(&listav[i], dt);
        }
    }
}
