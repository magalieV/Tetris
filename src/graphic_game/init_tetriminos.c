/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

void pause_loop(my_key_t key)
{
    int touch = 0;

    while (1) {
        touch = getch();
        if (touch == key.my_pad.key_pause)
            break;
    }
}

char **concat_element(char **map, object_t **tetriminos, my_game_t *game)
{
    if (on_line(map, tetriminos[0]->shem, game->pos, game->key.my_map.x)) {
        map = concat_map_and_piece(map, tetriminos[0]->shem, game->pos,
        game->key.my_map.x);
        game->pos.x = 0;
        game->pos.y = 0;
        tetriminos[0] = tetriminos[1];
        tetriminos[1] = choose_random_tetri(game->key);
        display_game_map(map, tetriminos, *game);
        if (on_line(map, tetriminos[0]->shem, game->pos, game->key.my_map.x))
            return (NULL);
    }
    return (map);
}

char **delete_line(char **map, my_game_t *game, object_t **tetriminos)
{
    int score = game->score;
    int line = game->line;

    if (line_entire(map, &score, &line)) {
        game->score = score;
        game->line = line;
        game->lines += 1;
        map = suppr_line(map, game->line);
        game->save += 1;
        if (game->save == 10) {
            if (game->speed - 0.05 > 0)
                game->speed -= 0.05;
            game->save = 0;
            game->level += 1;
        }
        display_game_map(map, tetriminos, *game);
    }
    return (map);
}

object_t **init_tetriminos_and_game(my_key_t *my_key, my_game_t *game)
{
    object_t **tetriminos = malloc(sizeof(object_t *) * 3);

    tetriminos[0] = choose_random_tetri(*my_key);
    tetriminos[1] = choose_random_tetri(*my_key);
    tetriminos[2] = 0;
    init_game_element(*my_key, game);
    init_key_for_game(my_key);
    game->key = *my_key;
    init_window();
    my_init_color();
    return (tetriminos);
}

void event_of_game(my_game_t *game, char **map, object_t **tetriminos)
{
    clock_t recup_clock;

    if (up_hight_score(game))
        display_game_map(map, tetriminos, *game);
    if (up_time(recup_clock, game))
        display_game_map(map, tetriminos, *game);
}
