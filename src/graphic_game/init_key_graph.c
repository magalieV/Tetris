/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

void my_init_color(void)
{
    start_color();
    init_pair(COLOR_RED, COLOR_RED, COLOR_RED);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_WHITE);
}

static int value_getc(int value)
{
    if (value == -1)
        return (KEY_LEFT);
    if (value == -2)
        return (KEY_RIGHT);
    if (value == -3)
        return (KEY_UP);
    if (value == -4)
        return (KEY_DOWN);
    return (value);
}

void init_key_for_game(my_key_t *my_key)
{
    my_key->my_pad.key_left = value_getc(my_key->my_pad.key_left);
    my_key->my_pad.key_right = value_getc(my_key->my_pad.key_right);
    my_key->my_pad.key_turn = value_getc(my_key->my_pad.key_turn);
    my_key->my_pad.key_drop = value_getc(my_key->my_pad.key_drop);
    my_key->my_pad.key_quit = value_getc(my_key->my_pad.key_quit);
    my_key->my_pad.key_pause = value_getc(my_key->my_pad.key_pause);
}

void pos_piece(my_pos_t *pos, char **tab, int x)
{
    int size = 0;
    int size_x = 0;

    for (size = 0; tab[size]; size++);
    for (size_x = 0; tab[1][size_x]; size_x++);
    pos->x = LINES / 2 - size / 2 + 1;
    pos->y = COLS / 2 - size_x / 2 + x / 2;
}

void init_game_element(my_key_t my_key, my_game_t *game)
{
    char **tab = NULL;
    int op = 0;

    op = open(".save_score.txt", O_RDONLY | O_CREAT, 0755);
    close(op);
    tab = read_doub_file(".save_score.txt");
    game->level = my_key.level;
    game->time = 0;
    game->score = 0;
    game->lines = 0;
    game->save = 0;
    game->line = 0;
    game->speed = 2;
    game->pos.x = 0;
    game->pos.y = 0;
    if (!tab)
        game->hight_score = 0;
    else
        game->hight_score = my_getnbrr(tab[0]);
}
