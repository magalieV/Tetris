/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

char **suppr_line(char **tab, int line)
{
    int size = my_tab_len(tab);
    int size_x = my_str_len(tab[0]);

    for (int i = line; i > 0; i--) {
        for (int j = 1; j < size_x - 1; j++) {
            if (i - 1 != 0)
                tab[i][j] = tab[i - 1][j];
            else
                tab[i][j] = ' ';
            }
        }
    return (tab);
}

bool line_entire(char **tab, int *level, int *line)
{
    int size = 0;
    int j = 0;
    int size_tab = my_tab_len(tab);
    int size_x = my_str_len(tab[0]);

    for (int i = 1; i < size_tab - 1; i++) {
        size = 0;
        for (j = 0; tab[i][j]; j++) {
            if (tab[i][j] == '*')
                size++;
        }
        if (size == j) {
            *line = i;
            *level += 1;
            return (true);
        }
    }
    return (false);
}

char **concat_map_and_piece(char **tab, char **piece, my_pos_t pos, int x)
{
    int size = my_tab_len(piece);
    int size_x = my_str_len(piece[0]);
    int x_tmp = 0;
    int y_tmp = 0;

    for (int i = 0; piece[i]; i++) {
        for (int j = 0; piece[i][j]; j++) {
            y_tmp = pos.y + i;
            x_tmp = pos.x + (x / 2) - (size_x / 2) + j;
            if (piece[i][j] == '*')
                tab[y_tmp][x_tmp] = piece[i][j];
        }
    }
    return (tab);
}

bool on_line(char **tab, char **piece, my_pos_t pos, int x)
{
    int size = my_tab_len(piece);
    int size_x = my_str_len(piece[0]);
    int x_tmp = 0;
    bool is_possible = false;
    int y_tmp = 0;

    for (int i = 0; piece[i]; i++) {
        for (int j = 0; piece[i][j]; j++) {
            is_possible = false;
            y_tmp = pos.y + i + 1;
            x_tmp = pos.x + (x / 2) - (size_x / 2) + j;
            if (piece[i][j] == '*' && tab[y_tmp] && tab[y_tmp][x_tmp])
                is_possible = true;
            if (x_tmp == 0 || x_tmp == x)
                is_possible = false;
            if (is_possible && tab[y_tmp][x_tmp] == '*')
                return (true);
        }
    }
    return (false);
}

object_t *choose_random_tetri(my_key_t key)
{
    int res_rand = 0;
    int count = 0;
    int nb_loop = 0;

    do {
        count = 0;
        res_rand = rand() % key.size_object;
        while (key.object->prev)
            key.object = key.object->prev;
        while (key.object && count < res_rand) {
            if (key.object->next == NULL)
                break;
            key.object = key.object->next;
            count++;
        }
        nb_loop++;
    } while (key.object->ok_or_ko && nb_loop < key.size_object);
    return (key.object);
}
