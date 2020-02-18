/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** get_nbr
*/

#include "printf_hd.h"

int my_getnbr(char const *str)
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
        else if ((number == 214748364 && str[i] > 7 + 48) || number > 214748364)
            return (0);
        number *=  10;
        number += str[i] - 48;
        i++;
    }
    return (number * a);
}

void binar_unsign(unsigned int number, between_t assign, char flag)
{
    my_putnbr_base(number, 2, 87, 0);
}

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}

int my_strlen_nb(int *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}
