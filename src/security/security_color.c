/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

void found_equal(char const *str, char *av)
{
    bool found = false;

    for (int i = 0; str[i]; i++)
        found = (str[i] == '=') ? true : found;
    if (found == false) {
        help(av);
        exit(84);
    }
}

bool if_color_exist(int color)
{
    if (color != COLOR_BLACK && color != COLOR_RED && color != COLOR_GREEN
    && color != COLOR_YELLOW)
        if (color != COLOR_BLUE && color != COLOR_MAGENTA && color != COLOR_CYAN
        && color != COLOR_WHITE)
            return (true);
    return (false);
}

bool too_much_information(char **str)
{
    int size = 0;

    if (!str)
        return (true);
    for (size = 0; str[size]; size++);
    if (size > 3)
        return (true);
    return (false);
}

bool bad_char_on_file(char **str)
{
    if (!str)
        return (true);
    for (int i = 0; str[i]; i++) {
        for (int j = 0; str[i][j]; j++) {
            if (str[i][j] != '*' && str[i][j] != '\n' && str[i][j] != ' ')
                return (true);
        }
    }
    return (false);
}
