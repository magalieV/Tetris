/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

static char *reverse_string(char *str)
{
    int size = my_str_len(str);
    char *string = malloc(sizeof(char) * (size + 1));
    int i = 0;

    if (size == 0 || !string)
        return (NULL);
    for (int j = size - 1; j >= 0; j--)
        string[i++] = str[j];
    string[i] = '\0';
    free(str);
    return (string);
}

char *number_to_string(int nb)
{
    char *string = NULL;
    int cpy = nb;
    int size = 0;
    int i = 0;

    if (nb == 0)
        size = 1;
    while (nb > 0) {
        size++;
        nb /= 10;
    }
    string = malloc(sizeof(char) * (size + 1));
    if (cpy == 0)
        string[i++] = cpy + 48;
    while (cpy > 0) {
        string[i++] = (cpy % 10) + 48;
        cpy /= 10;
    }
    string[i] = '\0';
    string = reverse_string(string);
    return (string);
}
