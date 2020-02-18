/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

void set_size_map(char **tmp, my_key_t *my_key)
{
    my_key->my_map.x = my_getnbr(tmp[0]);
    my_key->my_map.y = my_getnbr(tmp[1]);
}

int my_str_len(char *str)
{
    int size = 0;

    while (str && str[size])
        size++;
    return (size);
}

bool if_end_of_name(char const *str, int i)
{
    char *tmp = "tetrimino";
    int j = 0;

    if (str[i] != '.')
        return (false);
    i += 1;
    while (tmp[j] && str[i]) {
        if (tmp[j] != str[i])
            return (false);
        i++;
        j++;
    }
    if (str[i] != '\0')
        return (false);
    return (true);
}
