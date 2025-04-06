/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display fle
*/
#include "./include/my.h"

void davmanager(struct info *in, struct avion *l, int i)
{
    if (in->s == 0)
        sfRenderWindow_drawSprite(in->window, l[i].sprite, NULL);
    if (in->l == 0)
        sfRenderWindow_drawRectangleShape(in->window, l[i].hitbox, NULL);
}

void display_avion(struct avion *l, struct info *in, float sec)
{
    for (int i = 0; l[i].null != 1; i++) {
        sfVector2f vector;
        vector.x = l[i].xd;
        vector.y = l[i].yd;
        if (sec > l[i].t && l[i].alive == 1) {
            l[i].onscreen = 1;
            sfSprite_setPosition(l[i].sprite, vector);
            davmanager(in, l, i);
        }
    }
}

void display_tower(struct tower *listto, struct info *infor)
{
    for (int i = 0; listto[i].null != 1; i++) {
        if (infor->s == 0)
            sfRenderWindow_drawSprite(infor->window, listto[i].sprite, NULL);
        if (infor->l == 0)
            sfRenderWindow_drawCircleShape(infor->window, listto[i].zone, NULL);
    }
}

int end_condition(struct avion *listav)
{
    for (int i = 0; listav[i].null != 1; i++) {
        if (listav[i].alive == 1)
            return -1;
    }
    return 1;
}

void display(struct avion *listav, struct tower *listto, struct info *infor)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float sec;
    while (end_condition(listav) == -1) {
        time = sfClock_getElapsedTime(clock);
        sec = time.microseconds / 1000000.0;
        sfRenderWindow_clear(infor->window, sfBlack);
        sfRenderWindow_drawText(infor->window, infor->text, NULL);
        display_tower(listto, infor);
        display_avion(listav, infor, sec);
        deplacer(listav);
        sfRenderWindow_display(infor->window);
        verif_list_collision(listav, listto);
        if (get_event(infor) == -1)
            return;
    }
}
