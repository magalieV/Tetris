/*
** EPITECH PROJECT, 2018
** printf
** File description:
** printf
*/

#include "printf_hd.h"

void put_space(between_t assign)
{
    if (assign.space == 1)
        my_putchar(' ');
}

char *alloc_mem(char *str)
{
    int size = 0;
    char *temp;

    size = count_size(str);
    if (size != 0)
        temp = malloc(sizeof(char) * (size + 1));
    else {
        temp = malloc(1);
        temp[0] = '\0';
    }
    return (temp);
}

between_t found_number(char *str, int i, int *temp_2)
{
    char *temp;
    between_t strg;
    int size = 0;
    int k = 0;

    strg.space = 0;
    for (int j = 0; j != i; j++)
        *(str++);
    temp = alloc_mem(str);
    secu_str(str);
    for (k = 0; found_flag(*str) != 1; k++) {
        if (*str == ' ')
            strg.space = 1;
        else
            temp[k] = *str;
        *(str++);
        *temp_2 += 1;
    }
    temp[k] = '\0';
    strg.str = temp;
    return (strg);
}

int get_number(char const str)
{
    char *temp = "diupsScoxXb";

    for (int j = 0; temp[j]; j++) {
        if (str == temp[j])
            return (1);
        }
    return (0);
}

int my_printf(char const *str, ...)
{
    va_list list;
    between_t strg;
    int temp_2 = 1;
    int i = 0;

    if (!str)
        return (0);
    va_start(list, str);
    for (i = 0; str[i]; i++) {
        if (str[i] == '%' && str[i + 1] != '%') {
            strg = sepa_two(str, &i, &temp_2);
            i += temp_2;
            sepa_one(str[i], list, strg);
            (strg.str) ? free(strg.str) : 0;
        } else if (str[i] == '%') {
            1 ? my_putchar(str[i]), i += 1 : 0;
        } else
            my_putchar(str[i]);
    }
    va_end(list);
    return (0);
}
