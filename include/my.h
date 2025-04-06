/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MYRADA
    #define MYRADA
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <SFML/Graphics.h>
    #include <math.h>

struct avion{
    int xd;
    int yd;
    int xa;
    int ya;
    int v;
    int t;
    int alive;
    int onscreen;
    int null;
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    int vx;
    int vy;
};

struct tower{
    int x;
    int y;
    int r;
    int null;
    sfTexture *texture;
    sfSprite *sprite;
    sfCircleShape *zone;
};

struct info{
    sfRenderWindow *window;
    int l;
    int s;
    sfSprite *bg;
    sfTexture *texture;
    sfFont *font;
    sfText *text;
};

char *fs_open_file(const char *pathfile);
char **my_str_to_word_array(char const *str);
int my_get_nbr_i(char *str, int *i);
int my_strlen(char const *str);
int my_put_nbr(int nb);
void my_putstr(char *str);

struct avion* get_list_avion(char **info);
struct tower* get_list_tower(char **info);
struct info get_info(void);
void display(struct avion *listav, struct tower *listt, struct info *infor);
int get_event(struct info *infor);
void verif_list_collision(struct avion *listav, struct tower *listto);
int end_condition(struct avion *listav);
void deplacer(struct avion *listav);

int cptmot(char const *str);
int lentotal(char const *str);

int error_lines(char **liste);
#endif
