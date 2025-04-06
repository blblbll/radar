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

char *getfile(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "give 1 argument file\n", 21);
        return NULL;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        return NULL;
    }
    char *tmp = fs_open_file(argv[1]);
    if (tmp == NULL)
        return NULL;
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] != 'A' && tmp[i] != 'T' && tmp[i] != '\n' &&
            tmp[i] != ' ' && (tmp[i] < '0' || tmp[i] > '9')) {
            write(2, "wrong file\n", 11);
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
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
            infor->s = (infor->s == 0 ) ? 1 : 0;
            return 0;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
            infor->l = (infor->l == 0) ? 1 : 0;
            return 0;
    }
}

int verif_data(struct avion *listav, struct tower *listto, struct info infor)
{
    if (!infor.texture || !infor.font) {
        write(2, "background or font assets does not exist\n", 41);
        return -1;
    }
    if (!infor.window) {
        write(2, "window does not exist\n", 22);
        return -1;
    }
    for (int i = 0; listav[i].null != 1; i++)
        if (!listav[i].texture) {
            write(2, "plane asset does not exist\n", 27);
            return -1;
        }
    for (int i = 0; listto[i].null != 1; i++)
        if (!listto[i].texture) {
            write(2, "tower asset does not exist\n", 27);
            return -1;
        }
    return 0;
}

int main(int argc, char **argv)
{
    char *tmp = getfile(argc, argv);
    if (tmp == NULL)
        return 84;
    char **info = my_str_to_word_array(tmp);
    if (error_lines(info) == 84)
        return 84;
    struct avion *listav = get_list_avion(info);
    struct tower *listto = get_list_tower(info);
    struct info infor = get_info();
    if (verif_data(listav, listto, infor) == -1)
        return 84;
    while (sfRenderWindow_isOpen(infor.window)) {
        display(listav, listto, &infor);
        if (end_condition(listav) == 1) {
            sfRenderWindow_close(infor.window);
            write(1, "the planes arrived at their destination\n", 40);
            return 0;
        }
    }
    return 0;
}
