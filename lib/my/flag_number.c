/*
** EPITECH PROJECT, 2018
** flag number
** File description:
** flag number
*/

#include "printf_hd.h"
#include "separation_hd.h"

int flag_signed_sort(va_list list, char flag, between_t assign)
{
    int number = 0;

    number = va_arg(list, int);
    decim_assign(number, assign);
    return (0);
}

int flag_unsigned_sort(va_list list, char flag, between_t assign)
{
    unsigned int number = 0;

    number = va_arg(list, unsigned int);
    if (number == 0) {
        my_put_nbr(0);
        return (0);
    }
    for (int i = 0; SEPARATION_TAB[i].sort != NULL; i++) {
        if (flag == SEPARATION_TAB[i].flag) {
            SEPARATION_TAB[i].sort(number, assign, flag);
            return (0);
        }
    }
    return (84);
}

int flag_unsigned_sort_long(va_list list, char flag, between_t assign)
{
    unsigned long number = 0;

    number = va_arg(list, unsigned long);
    if (assign.space == 1)
        my_putchar(' ');
    my_putstr("0x");
    my_putnbr_base_long(number, 16, 87);
}

void my_putnbr_base(unsigned int nbr, int basen, int size_L, int bol)
{
    int i = 0;
    int *str;
    unsigned int copy = nbr;
    int size = 0;

    for (size  = 0; copy > 0; size++)
        copy /= basen;
    str = malloc(sizeof(int) * (size + 1));
    for (i = 0; nbr > 0; i++) {
        str[i] = nbr % basen;
        nbr = nbr / basen;
    }
    i--;
    put_zero(str, bol);
    for (int j = i; j >= 0; j--) {
        if (str[j] < 10)
            my_putchar(str[j] + 48);
        else
            my_putchar(str[j] + size_L);
    }
}

void my_putnbr_base_long(unsigned long nbr, int basen, int size_L)
{
    int i = 0;
    unsigned long *str;
    unsigned long copy = nbr;
    int size = 0;

    for (size  = 0; copy > 0; size++)
        copy /= basen;
    str = malloc(sizeof(unsigned long) * (size + 1));
    for (i = 0; nbr > 0; i++) {
        str[i]  = nbr % basen;
        nbr = nbr / basen;
    }
    i--;
    for (int j = i; j >= 0; j--) {
        if (str[j] < 10)
            my_putchar(str[j] + 48);
        else
            my_putchar(str[j] + size_L);
    }
}
