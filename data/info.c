/*
** EPITECH PROJECT, 2023
** info.c
** File description:
** info data
*/
#include "../include/my.h"

struct info get_info(void)
{
    struct info infor;
    infor.l = 0;
    infor.s = 0;
    sfVideoMode mod = {1920, 1080, 32};
    infor.window = sfRenderWindow_create(mod, "radar", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(infor.window, 60);
    infor.texture = sfTexture_createFromFile("assets/bg.jpg", NULL);
    infor.bg = sfSprite_create();
    sfSprite_setTexture(infor.bg, infor.texture, sfTrue);
    sfVector2f v;
    v.x = 0;
    v.y = 0;
    sfSprite_setPosition(infor.bg, v);
    infor.font = sfFont_createFromFile("assets/font.ttf");
    infor.text = sfText_create();
    sfText_setString(infor.text, "Press L for hitboxes\n Press S for sprites");
    sfText_setFont(infor.text, infor.font);
    sfText_setCharacterSize(infor.text, 20);
    sfText_setPosition(infor.text, v);
    return infor;
}
