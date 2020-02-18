/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"
#include <ncurses.h>

int init_window(void)
{
    initscr();
    curs_set(FALSE);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

int my_tab_len(char **tab)
{
    int size = 0;

    while (tab && tab[size])
        size++;
    return (size);
}

char **moove_piece_to_left(char **tab)
{
    int size_x = my_str_len(tab[0]);
    int size_y = my_tab_len(tab);
    char **new = malloc(sizeof(char *) * (size_x + 2));
    int x_ = 0;
    int y_ = 0;
    int tm = 0;

    for (int i = 0; i <= size_x; i++)
        new[i] = malloc(sizeof(size_y) + 1);
    while (size_x > 0) {
        for (int j = size_y - 1; j >= 0; j--) {
            new[y_][x_] = (tab[j][tm] && tab[j][tm] == '*') ? tab[j][tm] : ' ';
            x_++;
        }
        1 ? tm += 1, new[y_][x_] = '\0', y_ += 1, size_x -= 1, x_ = 0 : 0;
    }
    new[y_] = 0;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    return (new);
}

void display_game(my_key_t my_key)
{
    char **map = init_map_graph(my_key.my_map.x, my_key.my_map.y);
    clock_t recup_clock = clock();
    my_game_t gm = {0};
    int result = 0;
    object_t **tet = init_tetriminos_and_game(&my_key, &gm);

    display_game_map(map, tet, gm);
    while (1) {
        tet[0]->shem = key_is_press(gm.key, &gm.pos, tet[0]->shem, &result);
        if (result == 1)
            display_game_map(map, tet, gm);
        else if (result == 2)
            break;
        result = 0;
        if (fall_piece(recup_clock, &gm.pos.y, gm.speed))
            display_game_map(map, tet, gm);
        if ((map = concat_element(map, tet, &gm)) == NULL)
            break;
        1 ? map = delete_line(map, &gm, tet), event_of_game(&gm, map, tet) : 0;
    }
    endwin();
}
