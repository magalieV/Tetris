/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

char *display_piece_color(int color, char c, bool bol, char *tmp)
{
    if (bol) {
        tmp = malloc(sizeof(char) * 2);
        tmp[0] = c;
        tmp[1] = '\0';
        if (c == '*')
            attron(COLOR_PAIR(color));
        else
            attron(COLOR_PAIR(COLOR_BLACK));
    } else {
        if (tmp)
            free(tmp);
        tmp = NULL;
        if (c == '*')
            attroff(COLOR_PAIR(color));
        else
            attroff(COLOR_PAIR(COLOR_BLACK));
    }
    return (tmp);
}

void display_next(char **tab, int color)
{
    int size = 0;
    int size_y = 0;
    char *tmp = NULL;

    mvprintw(LINES / 4 - 2, (COLS / 4 * 3) - 3, "Next : ");
    for (size_y = 0; tab[size_y]; size_y++);
    size = my_str_len(tab[0]);
    if (LINES / 2 + 20 - size / 2 < 0 || COLS / 2 - size_y / 2 + 3 < 0) {
        free(tab);
        return;
    }
    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            tmp = display_piece_color(color, tab[i][j], true, tmp);
            mvprintw(LINES / 4 + i, (COLS / 4 * 3) + j, tmp);
            tmp = display_piece_color(color, tab[i][j], false, tmp);
        }
    }
}

void display_board(my_game_t game)
{
    char *tmp = number_to_string(game.hight_score);

    mvprintw(LINES / 2 - 2, COLS / 4 - 12, "Hight score ");
    mvprintw(LINES / 2 - 2, COLS / 4, tmp);
    free(tmp);
    mvprintw(LINES / 2 - 1, COLS / 4 - 6, "Score ");
    tmp = number_to_string(game.score);
    mvprintw(LINES / 2 - 1, COLS / 4, tmp);
    free(tmp);
    mvprintw(LINES / 2, COLS / 4 - 6, "Lines ");
    tmp = number_to_string(game.lines);
    mvprintw(LINES / 2, COLS / 4, tmp);
    free(tmp);
    mvprintw(LINES / 2 + 1, COLS / 4 - 6, "Level ");
    tmp = number_to_string(game.level);
    mvprintw(LINES / 2 + 1, COLS / 4, tmp);
    free(tmp);
    mvprintw(LINES / 2 + 2, COLS / 4 - 5, "Time ");
    tmp = number_to_string(game.time);
    mvprintw(LINES / 2 + 2, COLS / 4, tmp);
    free(tmp);
}

void display_piece(char **tab, my_pos_t pos, int color, char **map)
{
    int size = 0;
    int size_y = 0;
    char *tmp = NULL;
    int y = my_tab_len(map) / 2;

    for (size_y = 0; tab[size_y]; size_y++);
    size = my_str_len(tab[0]);
    if (LINES / 2 + 20 - size / 2 < 0 || COLS / 2 - size_y / 2 + 3 < 0) {
        free(tab);
        return;
    }
    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            tmp = display_piece_color(color, tab[i][j], true, tmp);
            if (tmp[0] == '*')
                mvprintw(LINES / 2 - y + i + pos.y,
                COLS / 2 - size / 2 + pos.x + j, tmp);
            tmp = display_piece_color(color, tab[i][j], false, tmp);
        }
    }
}
