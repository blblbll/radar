/*
** EPITECH PROJECT, 2023
** info.c
** File description:
** info data
*/
#include "../include/my.h"

static void init_text(struct info *infor)
{
    sfVector2f v = {0, 0};

    infor->font = sfFont_createFromFile("assets/font.ttf");
    infor->text = sfText_create();
    infor->timer = sfText_create();
    sfText_setString(infor->text, "Press L for hitboxes\nPress S for sprites");
    sfText_setCharacterSize(infor->text, 20);
    sfText_setPosition(infor->text, v);
    sfText_setCharacterSize(infor->timer, 30);
    if (infor->font != NULL) {
        sfText_setFont(infor->text, infor->font);
        sfText_setFont(infor->timer, infor->font);
    }
}

struct info get_info(void)
{
    struct info infor;
    sfVideoMode mod = {1920, 1080, 32};

    infor.l = 0;
    infor.s = 0;
    infor.bg = NULL;
    infor.texture = NULL;
    infor.window = sfRenderWindow_create(mod, "radar", sfClose, NULL);
    if (infor.window == NULL) {
        infor.font = NULL;
        infor.text = NULL;
        infor.timer = NULL;
        return infor;
    }
    sfRenderWindow_setFramerateLimit(infor.window, 60);
    infor.texture = sfTexture_createFromFile("assets/bg.jpg", NULL);
    infor.bg = sfSprite_create();
    if (infor.texture != NULL)
        sfSprite_setTexture(infor.bg, infor.texture, sfTrue);
    init_text(&infor);
    return infor;
}
