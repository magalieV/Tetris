/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "header.h"

static char *strcat_mall(char *dest, char const *cpy)
{
    int size_dest = 0;
    int size_cpy = 0;
    char *new = NULL;
    int k = 0;

    if (dest)
        for (size_dest = 0; dest[size_dest]; size_dest++);
    if (cpy)
        for (size_cpy = 0; cpy[size_cpy]; size_cpy++);
    new = malloc(sizeof(char) * (size_cpy + size_dest + 2));
    if (dest) {
        for (int i = 0; dest[i]; i++)
            new[k++] = dest[i];
    }
    for (int j = 0; cpy[j]; j++)
        new[k++] = cpy[j];
    new[k++] = '\n';
    new[k] = '\0';
    if (dest)
        free(dest);
    return (new);
}

static char *my_read_file(char const *str)
{
    char *tmp = NULL;
    char *fin = NULL;
    int op = 0;

    op = open(str, O_RDONLY);
    if (op == -1)
        exit(84);
    while (tmp = get_next_line(op)) {
        fin = strcat_mall(fin, tmp);
        free(tmp);
    }
    close(op);
    return (fin);
}

char **read_doub_file(char const *str)
{
    char *tmp = NULL;
    char **button = NULL;

    tmp = my_read_file(str);
    if (tmp == NULL)
        return (NULL);
    button = my_str_to_word_array_up(tmp, "\n");
    free(tmp);
    return (button);
}
