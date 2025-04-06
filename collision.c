/*
** EPITECH PROJECT, 2023
** collision.c
** File description:
** checking collisions
*/
#include "./include/my.h"

int collision_cercle(struct tower cercle, struct avion rect)
{
    int cxcercle = cercle.x + cercle.r;
    int cycercle = cercle.y + cercle.r;
    int cxrect = rect.xd + 10;
    int cyrect = rect.yd + 10;
    float dist = sqrt(pow(cxcercle - cxrect, 2) + pow(cycercle - cyrect, 2));
    int distx = abs(cxcercle - cxrect);
    int disty = abs(cycercle - cyrect);
    if (dist < cercle.r)
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
    int left1 = av1.yd;
    int left2 = av2.yd;
    int taille = 20;
    int top1 = av1.xd;
    int top2 = av2.xd;
    if (left1 < left2 + taille && left1 + taille > left2
        && top1 < top2 + taille && top1 + taille > top2) {
        return 1;
    }
    return -1;
}

void if_col(struct avion *listav, int i, int j, struct tower *listto)
{
    if (listav[i].onscreen == 1 && listav[i].alive == 1 &&
        listav[j].onscreen == 1 && listav[j].alive == 1 && i != j)
        if (verif_collision(listav[i], listav[j]) == 1 &&
            (collision_list_cercle(listto, listav[i]) == -1) &&
            (collision_list_cercle(listto, listav[j]) == -1)) {
            listav[i].alive = 0;
            listav[j].alive = 0;
            listav[i].onscreen = 0;
            listav[j].onscreen = 0;
            sfSprite_destroy(listav[i].sprite);
            sfSprite_destroy(listav[j].sprite);
            sfRectangleShape_destroy(listav[i].hitbox);
            sfRectangleShape_destroy(listav[j].hitbox);
        }
}

void verif_list_collision(struct avion *listav, struct tower *listto)
{
    for (int i = 0; listav[i].null != 1; i++)
        for (int j = 0; listav[j].null != 1; j++)
            if_col(listav, i, j, listto);
}
