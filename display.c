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

void display_avion(struct avion *l, struct info *in)
{
    for (int i = 0; l[i].null != 1; i++) {
        if (l[i].onscreen == 1 && l[i].alive == 1)
            davmanager(in, l, i);
    }
}

void display_tower(struct tower *listto, struct info *infor)
{
    for (int i = 0; listto[i].null != 1; i++) {
        if (infor->s == 0)
            sfRenderWindow_drawSprite(infor->window, listto[i].sprite, NULL);
        if (infor->l == 0)
            sfRenderWindow_drawCircleShape(infor->window, listto[i].zone,
            NULL);
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

static void display_timer(struct info *infor, float sec)
{
    char buf[32];
    int len = 0;
    sfFloatRect rect;
    sfVector2f pos;

    my_int_to_str((int) sec, buf);
    while (buf[len] != '\0')
        len++;
    buf[len] = 's';
    buf[len + 1] = '\0';
    sfText_setString(infor->timer, buf);
    rect = sfText_getGlobalBounds(infor->timer);
    pos.x = 1920 - rect.width - 15;
    pos.y = 10;
    sfText_setPosition(infor->timer, pos);
    sfRenderWindow_drawText(infor->window, infor->timer, NULL);
}

static void draw_frame(struct avion *listav, struct tower *listto,
    struct info *infor, float sec)
{
    sfRenderStates states = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    sfTransform_scale(&states.transform, 1920.0 / BG_WIDTH,
    1080.0 / BG_HEIGHT);
    sfRenderWindow_clear(infor->window, sfBlack);
    sfRenderWindow_drawSprite(infor->window, infor->bg, &states);
    sfRenderWindow_drawText(infor->window, infor->text, NULL);
    display_timer(infor, sec);
    display_tower(listto, infor);
    display_avion(listav, infor);
    sfRenderWindow_display(infor->window);
}

void display(struct avion *listav, struct tower *listto, struct info *infor)
{
    sfClock *clock = sfClock_create();
    float sec = 0;
    float last = 0;
    float dt = 0;

    while (end_condition(listav) == -1) {
        sec = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        dt = sec - last;
        last = sec;
        if (dt > 0.1)
            dt = 0.1;
        takeoff(listav, sec);
        deplacer(listav, dt);
        verif_list_collision(listav, listto);
        draw_frame(listav, listto, infor, sec);
        if (get_event(infor) == -1)
            break;
    }
    sfClock_destroy(clock);
}
