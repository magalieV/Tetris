/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

char **key_is_press(my_key_t my_key, my_pos_t *pos, char **tab, int *result)
{
    int touch = getch();

    if (touch == my_key.my_pad.key_quit)
        *result = 2;
    if (touch == my_key.my_pad.key_turn) {
        tab = moove_piece_to_left(tab);
        *result = 1;
    }
    if (touch == my_key.my_pad.key_drop) {
        pos->y += 1;
        *result = 1;
    }
    if (touch == my_key.my_pad.key_left)
        1 ? pos->x -= 1, *result = 1 : 0;
    if (touch == my_key.my_pad.key_right)
        1 ? pos->x += 1, *result = 1 : 0;
    if (touch == my_key.my_pad.key_pause)
        pause_loop(my_key);
    return (tab);
}

bool fall_piece(clock_t my_clock, int *y_more, float time_speed)
{
    static float time_pass = 0.0;
    float speed = 0.0;

    my_clock = clock();
    speed = (double)my_clock / CLOCKS_PER_SEC;
    if (speed - time_speed >= time_pass) {
        *y_more += 1;
        time_pass = speed;
        return (true);
    }
    return (false);
}

void display_game_map(char **map, object_t **object, my_game_t game)
{
    clear();
    display_map(map);
    display_piece(object[0]->shem, game.pos, object[0]->color, map);
    display_board(game);
    if (game.key.next)
        display_next(object[1]->shem, object[1]->color);
    refresh();
}

bool up_time(clock_t my_clock, my_game_t *game)
{
    float speed = 0;

    my_clock = clock();
    speed = (double)my_clock / CLOCKS_PER_SEC;
    if (speed - 1 >= game->time) {
        game->time = (int)speed;
        return (true);
    }
    return (false);
}

bool up_hight_score(my_game_t *game)
{
    int op = 0;
    char *number = number_to_string(game->level);

    if (game->score > game->hight_score) {
        game->hight_score = game->score;
        op = open(".save_score.txt", O_CREAT | O_WRONLY);
        write(op, number, my_str_len(number));
        close(op);
        return (true);
    }
    return (false);
}
