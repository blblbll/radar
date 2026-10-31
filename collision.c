/*
** EPITECH PROJECT, 2023
** collision.c
** File description:
** checking collisions
*/
#include "./include/my.h"

int collision_cercle(struct tower cercle, struct avion plane)
{
    float dx = cercle.x - plane.xd;
    float dy = cercle.y - plane.yd;

    if (dx * dx + dy * dy <= (float) cercle.r * cercle.r)
        return 1;
    return -1;
}

int collision_list_cercle(struct tower *listto, struct avion plane)
{
    for (int i = 0; listto[i].null != 1; i++) {
        if (collision_cercle(listto[i], plane) == 1)
            return 1;
    }
    return -1;
}

int verif_collision(struct avion av1, struct avion av2)
{
    if (fabsf(av1.xd - av2.xd) < PLANE_SIZE &&
        fabsf(av1.yd - av2.yd) < PLANE_SIZE)
        return 1;
    return -1;
}

static void destroy_both(struct avion *av1, struct avion *av2)
{
    destroyspri(av1);
    destroyspri(av2);
}

static void if_col(struct avion *listav, int i, int j, struct tower *listto)
{
    if (listav[i].onscreen != 1 || listav[i].alive != 1 ||
        listav[j].onscreen != 1 || listav[j].alive != 1)
        return;
    if (verif_collision(listav[i], listav[j]) == 1 &&
        collision_list_cercle(listto, listav[i]) == -1 &&
        collision_list_cercle(listto, listav[j]) == -1)
        destroy_both(&listav[i], &listav[j]);
}

void verif_list_collision(struct avion *listav, struct tower *listto)
{
    for (int i = 0; listav[i].null != 1; i++)
        for (int j = i + 1; listav[j].null != 1; j++)
            if_col(listav, i, j, listto);
}
