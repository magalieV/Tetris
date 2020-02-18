/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** SECU_STRING
*/

#include "printf_hd.h"

void test_secu(int *bol, int *bol_2, char str, char temp)
{
    if (str == '%')
        *bol = 1;
    else if (*bol == 0 && str == temp)
        *bol_2 = 1;
}

char *my_strdup_print(char *str)
{
    int i = 0;
    int size = 0;
    char *new = NULL;

    if (!str)
        return (NULL);
    for (size = 0; str[size]; size++);
    new = malloc(sizeof(char) * (size + 1));
    if (!new)
        return (NULL);
    for (i = 0; str[i]; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}
