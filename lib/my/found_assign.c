/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** FOUND_ASSIGN
*/

#include "printf_hd.h"

int found_assign_str(char c)
{
    char *temp = "+-.#";

    for (int i = 0; temp[i]; i++) {
        if (c == temp[i])
            return (1);
    }
    return (0);
}

int found_flag(char c)
{
    char *temp = "diupsScoxXmb";

    for (int i = 0; temp[i]; i++) {
        if (c == temp[i])
            return (1);
    }
    return (0);
}

int count_size(char *str)
{
    char *temp = str;
    int size = 0;
    int bol = 0;

    while (found_flag(*temp) != 1) {
        if (*temp != ' ')
            bol = 1;
        size++;
        *(temp++);
    }
    if (bol == 1)
        return (size);
    return (0);
}

int put_more(between_t assign, int nb, int recup)
{
    int bol = 0;
    int bol_2 = 0;

    if (recup == 84)
        return (84);
    if (nb >= 0)
        bol = 1;
    for (int i = 0; assign.str[i]; i++) {
        if (assign.str[i] == '+')
            bol_2 = 1;
    }
    if (bol == 1 && bol_2 == 1)
        my_putchar('+');
    return (0);
}

void unsign_dec(unsigned int number, between_t assign, char flag)
{
    my_put_nbr_u(number);
}
