/*
** EPITECH PROJECT, 2019
** bootsrap_tetris
** File description:
** __DESCRIPTION__
*/

#include "header.h"

int my_getnbrr(char const *str)
{
    int i = 0;
    int number = 0;
    int a = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            a *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (number == 214748364 && str[i] == 8 + 48 && a == -1 &&
            !(str[i + 1] < 58 && str[i + 1] > 47))
            return (-2147483648);
        else if ((number == 214748364 && str[i] > 7 + 48) ||
        number > 214748364)
            return (0);
        number *= 10;
        number += str[i] - 48;
        i++;
    }
    return (number * a);
}

char *concat_my_path_terminos(char *str)
{
    int size = my_str_len(str) + 10;
    char *new = malloc(sizeof(char) * (size + 2));
    char *path = "tetriminos";
    int k = 0;

    for (int i = 0; path[i]; i++)
        new[k++] = path[i];
    new[k++] = '/';
    for (int i = 0; str[i]; i++)
        new[k++] = str[i];
    new[k] = '\0';
    return (new);
}

char *remove_type_path(char *path)
{
    int size = my_str_len(path);
    char *new = malloc(sizeof(char) * (size + 1));
    int k = 0;
    bool bol = true;

    for (int i = 0; path[i]; i++) {
        if (if_end_of_name(path, i)) {
            bol = false;
            break;
        } else
            new[k++] = path[i];
    }
    if (bol)
        return (NULL);
    new[k] = '\0';
    return (new);
}

object_t *check_info_file(char const *path, object_t *begin)
{
    char **buffer = NULL;
    char **tmp = NULL;
    object_t *object = malloc(sizeof(object_t));

    object = init_my_object(path, object, begin);
    begin ? begin->next = object : 0;
    buffer = recup_buffer(path);
    if (!buffer || !object->name) {
        1 ? destroy_multi_tab(buffer), object->ok_or_ko = true : 0;
        return (object);
    }
    tmp = my_str_to_word_array_up(buffer[0], " ");
    object->ok_or_ko = if_number_is_ok(tmp);
    if (object->ok_or_ko) {
        1 ? destroy_multi_tab(buffer), destroy_multi_tab(tmp) : 0;
        return (object);
    }
    object = init_my_shem(buffer, object);
    object = fill_my_number(tmp, object);
    object = size_correspond(object);
    return (object);
}

object_t *init_object(my_key_t *key)
{
    DIR *dir = NULL;
    struct dirent *file = NULL;
    object_t *my_object = NULL;

    key->size_object = size_of_information();
    dir = opendir("tetriminos");
    if (!dir)
        exit(84);
    my_object = create_object(dir, key, my_object);
    closedir(dir);
    while (my_object && my_object->prev)
        my_object = my_object->prev;
    my_object = sort_list_object(my_object);
    return (my_object);
}
