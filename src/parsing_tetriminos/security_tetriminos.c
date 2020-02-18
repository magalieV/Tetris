/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

object_t *create_object(DIR *dir, my_key_t *key, object_t *my_object)
{
    char *name_temp = NULL;
    struct dirent *file = NULL;

    while ((file = readdir(dir)) != NULL) {
        name_temp = remove_type_path(file->d_name);
        if (my_strncmp(file->d_name, ".") != 0
        && my_strncmp(file->d_name, "..") != 0 && name_temp) {
            my_object = check_info_file(file->d_name, my_object);
            if (!my_object->name)
                key->size_object -= 1;
            my_object->ok_or_ko = check_size_tetrimino(my_object->x,
            my_object->y, key->my_map.x, key->my_map.y) ? true
            : my_object->ok_or_ko;
        }
        if (name_temp)
            free(name_temp);
    }
    return (my_object);
}

int size_of_information(void)
{
    struct dirent *tmp = NULL;
    DIR *dir = NULL;
    int size = 0;

    dir = opendir("tetriminos");
    if (!dir)
        exit(84);
    tmp = readdir(dir);
    while (tmp != NULL) {
        if (my_strncmp(tmp->d_name, ".") != 0
        && my_strncmp(tmp->d_name, "..") != 0)
            size++;
        tmp = readdir(dir);
    }
    closedir(dir);
    return (size);
}

bool check_size_tetrimino(int x, int y, int size_x, int size_y)
{
    if (x < 0 || x >= size_x || y < 0 || y >= size_y)
        return (true);
    return (false);
}

static char **remove_first_line(char **buffer)
{
    int size = 0;
    int k = 0;
    char **new = NULL;

    if (!buffer)
        return (NULL);
    for (size = 0; buffer[size]; size++);
    new = malloc(sizeof(char *) * (size));
    if (!buffer[1])
        return (NULL);
    for (int i = 1; buffer[i]; i++)
        new[k++] = my_strdup_print(buffer[i]);
    new[k] = 0;
    return (new);
}

object_t *init_my_shem(char **buffer, object_t *object)
{
    object->shem = remove_first_line(buffer);
    if (object->shem == NULL || bad_char_on_file(object->shem))
        object->ok_or_ko = true;
    destroy_multi_tab(buffer);
    return (object);
}
