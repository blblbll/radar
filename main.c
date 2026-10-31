/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include "./include/my.h"

void help(void)
{
    my_putstr("Air traffic simulation panel\n\nUSAGE\n");
    my_putstr("    ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("    path_to_script    The path to the script file.\n\n");
    my_putstr("OPTIONS\n    -h    print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n    'L' key    enable/disable hitboxes and ");
    my_putstr("areas.\n    'S' key    enable/disable sprites.\n");
}

static int bad_arguments(int argc)
{
    char buf[32];

    my_int_to_str(argc - 1, buf);
    my_puterr("./my_radar: bad arguments: ");
    my_puterr(buf);
    my_puterr(" given but 1 is required\nretry with -h\n");
    return 84;
}

static int is_valid_char(char c)
{
    return (c == 'A' || c == 'T' || c == '\n' || c == '\r' || c == ' ' ||
        c == '\t' || (c >= '0' && c <= '9'));
}

char *getfile(char *path)
{
    char *tmp = fs_open_file(path);

    if (tmp == NULL)
        return NULL;
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (!is_valid_char(tmp[i])) {
            my_puterr("wrong file\n");
            free(tmp);
            return NULL;
        }
    }
    return tmp;
}

int get_event(struct info *infor)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(infor->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(infor->window);
            return -1;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
            infor->s = (infor->s == 0) ? 1 : 0;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
            infor->l = (infor->l == 0) ? 1 : 0;
    }
    return 0;
}

int verif_data(struct avion *listav, struct tower *listto, struct info infor)
{
    if (!infor.window) {
        my_puterr("window does not exist\n");
        return -1;
    }
    if (!infor.texture || !infor.font) {
        my_puterr("background or font assets does not exist\n");
        return -1;
    }
    for (int i = 0; listav[i].null != 1; i++)
        if (!listav[i].texture) {
            my_puterr("plane asset does not exist\n");
            return -1;
        }
    for (int i = 0; listto[i].null != 1; i++)
        if (!listto[i].texture) {
            my_puterr("tower asset does not exist\n");
            return -1;
        }
    return 0;
}

static void free_planes_towers(struct avion *listav, struct tower *listto)
{
    for (int i = 0; listav != NULL && listav[i].null != 1; i++) {
        sfSprite_destroy(listav[i].sprite);
        sfRectangleShape_destroy(listav[i].hitbox);
    }
    for (int i = 0; listto != NULL && listto[i].null != 1; i++) {
        sfSprite_destroy(listto[i].sprite);
        sfCircleShape_destroy(listto[i].zone);
    }
    free(listav);
    free(listto);
}

void free_all(char **lines, struct avion *listav, struct tower *listto,
    struct info *infor)
{
    for (int i = 0; lines != NULL && lines[i] != NULL; i++)
        free(lines[i]);
    free(lines);
    free_planes_towers(listav, listto);
    free_avion_texture();
    free_tower_texture();
    if (infor->text != NULL)
        sfText_destroy(infor->text);
    if (infor->timer != NULL)
        sfText_destroy(infor->timer);
    if (infor->font != NULL)
        sfFont_destroy(infor->font);
    if (infor->bg != NULL)
        sfSprite_destroy(infor->bg);
    if (infor->texture != NULL)
        sfTexture_destroy(infor->texture);
    if (infor->window != NULL)
        sfRenderWindow_destroy(infor->window);
}

static int run(char *tmp)
{
    char **lines = my_str_to_word_array(tmp);
    struct avion *listav = NULL;
    struct tower *listto = NULL;
    struct info infor;
    int ret = 84;

    free(tmp);
    if (lines == NULL || error_lines(lines) == 84) {
        free_all(lines, NULL, NULL, &(struct info){0});
        return 84;
    }
    listav = get_list_avion(lines);
    listto = get_list_tower(lines);
    infor = get_info();
    if (listav != NULL && listto != NULL && verif_data(listav, listto, infor)
        != -1) {
        display(listav, listto, &infor);
        if (end_condition(listav) == 1)
            my_putstr("the planes arrived at their destination\n");
        ret = 0;
    }
    free_all(lines, listav, listto, &infor);
    return ret;
}

int main(int argc, char **argv)
{
    char *tmp = NULL;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' &&
        argv[1][2] == '\0') {
        help();
        return 0;
    }
    if (argc != 2)
        return bad_arguments(argc);
    tmp = getfile(argv[1]);
    if (tmp == NULL)
        return 84;
    return run(tmp);
}
