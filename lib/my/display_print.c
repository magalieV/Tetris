/*
** EPITECH PROJECT, 2018
** display
** File description:
** display
*/

#include "printf_hd.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int number_mod = nb;
    int number_div;

    if (nb >= 10) {
        number_mod = nb % 10;
        number_div = nb / 10;
        my_put_nbr(number_div);
        nb = number_mod;
    }
    my_putchar(nb + 48);
    return (0);
}

void my_put_nbr_u(unsigned int nb)
{
    unsigned int number_mod = nb;
    unsigned int number_div;

    if (nb >= 10) {
        number_mod = nb % 10;
        number_div = nb / 10;
        my_put_nbr_u(number_div);
        nb = number_mod;
    }
    my_putchar(nb + 48);
}

int my_putstr(char *str)
{
    if (!str) {
        my_putstr("(null)");
        return (0);
    }
    for (int k = 0; str[k]; k++)
        write(1, &str[k], 1);
    return (1);
}

void attribut_space(between_t assign, int size, char symb, int k)
{
    char *temp = assign.str;
    int number = 0;

    for (int j = 0; j != k; j++)
        *(temp++);
    number = my_getnbr(temp) - size;
    for (int i = 0; i < number; i++)
        my_putchar(symb);
}
