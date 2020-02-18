/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

static int sort_list_object_swap(
    object_t **my_object,
    object_t *obj1,
    object_t *obj2)
{
    obj1->next = obj2->next;
    obj2->prev = obj1->prev;
    obj1->prev = obj2;
    obj2->next = obj1;
    if (obj1->next)
        obj1->next->prev = obj1;
    if (obj2->prev)
        obj2->prev->next = obj2;
    else
        *my_object = obj2;
    return (0);
}

int strcompp(const char *str1, const char *str2)
{
    int i = 0;

    for (i = 0 ; str1[i] == str2[i]; i++);
    return (str1[i] - str2[i]);
}

object_t *sort_list_object(object_t *my_object)
{
    if (!my_object)
        return (my_object);
    for (object_t *cmn = my_object->next ; cmn ; cmn = cmn->next) {
        if (strcompp(cmn->prev->name, cmn->name) > 0) {
            sort_list_object_swap(&my_object, cmn->prev, cmn);
            cmn = my_object;
        }
    }
    return (my_object);
}

void print_my_tetriminos(my_key_t my_key)
{
    my_printf("Tetriminos :  %d\n", my_key.size_object);
    while (my_key.object) {
        if (my_key.object->name) {
            if (my_key.object->ok_or_ko) {
                my_printf("Tetriminos :  Name %s :  Error\n",
                my_key.object->name);
            } else {
                my_printf("Tetriminos :  Name %s :  Size %d*%d :  Color %d :\n",
                my_key.object->name, my_key.object->x, my_key.object->y,
                my_key.object->color);
                if (my_key.object->shem) {
                    for (int j = 0; my_key.object->shem[j]; j++)
                        my_printf("%s\n", my_key.object->shem[j]);
                    }
                }
            }
        if (my_key.object->next == NULL)
            break;
        my_key.object = my_key.object->next;
    }
}
