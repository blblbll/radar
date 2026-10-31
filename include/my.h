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

    #define PLANE_SIZE 20
    #define TOWER_SIZE 50
    #define BG_WIDTH 1920.0
    #define BG_HEIGHT 1021.0

struct avion{
    float xd;
    float yd;
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
    sfText *timer;
};

char *fs_open_file(const char *pathfile);
char **my_str_to_word_array(char const *str);
int my_get_nbr_i(char *str, int *i);
int my_strlen(char const *str);
int my_put_nbr(int nb);
void my_putstr(char *str);
void my_puterr(char *str);
void my_int_to_str(int nb, char *buf);

struct avion* get_list_avion(char **info);
struct tower* get_list_tower(char **info);
struct info get_info(void);
void free_avion_texture(void);
void free_tower_texture(void);
void display(struct avion *listav, struct tower *listt, struct info *infor);
int get_event(struct info *infor);
void verif_list_collision(struct avion *listav, struct tower *listto);
int end_condition(struct avion *listav);
void destroyspri(struct avion *av);
void takeoff(struct avion *listav, float sec);
void deplacer(struct avion *listav, float dt);
void free_all(char **lines, struct avion *listav, struct tower *listto,
    struct info *infor);

int cptmot(char const *str);
int lentotal(char const *str);

int error_lines(char **liste);
#endif
