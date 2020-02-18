/*
** EPITECH PROJECT, 2019
** bootsrap_tetris
** File description:
** __DESCRIPTION__
*/

#include "header.h"

int my_strncmp(char const *sa, char const *sb)
{
    return (!*sa || (*sa != *sb) ? (*sa - *sb) : my_strncmp(sa + 1, sb + 1));
}

void print_key(pad_t my_pad)
{
    display_key_info("Key Left :  ", my_pad.key_left);
    display_key_info("Key Right :  ", my_pad.key_right);
    display_key_info("Key Turn :  ", my_pad.key_turn);
    display_key_info("Key Drop :  ", my_pad.key_drop);
    display_key_info("Key Quit :  ", my_pad.key_quit);
    display_key_info("Key Pause :  ", my_pad.key_pause);
}

void display_debug_mode(my_key_t my_key)
{
    my_printf("*** DEBUG MODE ***\n");
    print_key(my_key.my_pad);
    if (!my_key.next)
        my_printf("Next :  No\n");
    else
        my_printf("Next :  Yes\n");
    my_printf("Level :  %d\n", my_key.level);
    my_printf("Size :  %d*%d\n", my_key.my_map.x, my_key.my_map.y);
    print_my_tetriminos(my_key);
}
