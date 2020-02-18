/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

static char *return_arrow(int pad)
{
    if (pad == -1)
        return ("^EOD");
    if (pad == -2)
        return ("^EOC");
    if (pad == -3)
        return ("^EOA");
    if (pad == -4)
        return ("^EOB");
    if (pad == ' ')
        return ("(space)");
    return (NULL);
}

void display_key_info(char const *str, int key)
{
    char *tmp = return_arrow(key);

    my_printf(str);
    if (tmp) {
        my_printf(tmp);
    } else {
        write(1, &key, 1);
    }
    write(1, "\n", 1);
}
