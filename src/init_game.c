/*
** EPITECH PROJECT, 2019
** d
** File description:
** d
*/

#include "header.h"

void init_pad(pad_t *my_pad)
{
    my_pad->key_left = -1;
    my_pad->key_right = -2;
    my_pad->key_turn = -3;
    my_pad->key_drop = -4;
    my_pad->key_quit = 'q';
    my_pad->key_pause = ' ';
}

void init_map(map_t *my_map)
{
    my_map->x = 20;
    my_map->y = 10;
}

my_key_t init_my_key(char **av)
{
    my_key_t my_key = {0};

    init_pad(&my_key.my_pad);
    my_key.next = true;
    my_key.level = 1;
    init_map(&my_key.my_map);
    my_key.object = init_object(&my_key);
    return (my_key);
}
