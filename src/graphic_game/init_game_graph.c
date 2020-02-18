/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

char **init_map_graph(int x, int y)
{
    char **tab = malloc(sizeof(char *) * (y + 1));
    int i = 0;

    tab[0] = malloc(sizeof(char) * (x + 1));
    for (i = 0; i < x; i++)
        tab[0][i] = '*';
    tab[0][i] = '\0';
    for (int j = 1; j < y - 1; j++) {
        tab[j] = malloc(sizeof(char) * (x + 1));
        tab[j][0] = '*';
        for (int e = 1; e < x - 1; e++)
            tab[j][e] = ' ';
        tab[j][x - 1] = '*';
        tab[j][x] = '\0';
    }
    tab[y - 1] = malloc(sizeof(char) * (x + 1));
    for (i = 0; i < x; i++)
        tab[y - 1][i] = '*';
    tab[y - 1][i] = '\0';
    tab[y] = 0;
    return (tab);
}

void display_map(char **tab)
{
    char *tmp = NULL;
    int size_x = my_str_len(tab[0]);
    int size_y = my_tab_len(tab);

    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            tmp = display_piece_color(COLOR_WHITE, tab[i][j], true, tmp);
            if (tmp[0] == '*')
                mvprintw((LINES / 2) - (size_y / 2) + i,
                (COLS) / 2 - (size_x / 2) + j, tmp);
            tmp = display_piece_color(COLOR_WHITE, tab[i][j], false, tmp);
        }
    }
}
