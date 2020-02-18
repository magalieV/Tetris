/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

object_t *size_correspond(object_t *object)
{
    int size = 0;
    int size_x = 0;

    if (object->shem == NULL)
        return (object);
    size = my_tab_len(object->shem);
    size_x = my_str_len(object->shem[0]);
    if (size != object->y || size_x != object->x)
        object->ok_or_ko = true;
    return (object);
}
