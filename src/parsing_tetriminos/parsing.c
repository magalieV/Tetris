/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

object_t *init_my_object(char const *path, object_t *object, object_t *begin)
{
    object->shem = NULL;
    object->ok_or_ko = false;
    object->name = remove_type_path((char *)path);
    object->prev = NULL;
    object->next = NULL;
    object->x = 0;
    object->y = 0;
    if (begin == NULL) {
        object->prev = NULL;
    } else {
        object->prev = begin;
    }
    return (object);
}

object_t *change_next_and_prev(object_t *object, object_t *begin)
{
    object->next = NULL;
    object->prev = NULL;
    if (begin == NULL) {
        object->prev = NULL;
    } else {
        object->prev = begin;
        begin->next = object;
    }
    return (object);
}

bool if_number_is_ok(char **tmp)
{
    int size = 0;

    for (size = 0; tmp[size]; size++);
    if (size < 3 || size > 3)
        return (true);
    if (!tmp[0] || (tmp[0][0] != '0' && my_getnbrr(tmp[0]) <= 0))
        return (true);
    if (!tmp[1] || (tmp[1][0] != '0' && my_getnbrr(tmp[1]) <= 0))
        return (true);
    if (!tmp[2] || (tmp[2][0] != '0' && my_getnbrr(tmp[2]) <= 0))
        return (true);
    if (too_much_information(tmp))
        return (true);
    return (false);
}

char **recup_buffer(char const *path)
{
    char **buffer = NULL;
    char *path_tmp = NULL;

    path_tmp = concat_my_path_terminos((char *)path);
    buffer = read_doub_file(path_tmp);
    if (path_tmp)
        free(path_tmp);
    return (buffer);
}

object_t *fill_my_number(char **tmp, object_t *object)
{
    object->x = my_getnbrr(tmp[0]);
    object->y = my_getnbrr(tmp[1]);
    object->color = my_getnbrr(tmp[2]);
    object->ok_or_ko = if_color_exist(object->color) ? true : object->ok_or_ko;
    destroy_multi_tab(tmp);
    return (object);
}
