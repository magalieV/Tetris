/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** ERR_rec
*/

#include "printf_hd.h"

int get_nbr(between_t assign, int *k)
{
    int bol = 0;

    while (assign.str[*k] < '1' || assign.str[*k] > '9') {
        if ((assign.str[*k] < '1' || assign.str[*k] > '9')
        && assign.str[*k] != '#' && assign.str[*k + 1] == '\0')
            return (81);
        if (assign.str[*k] == '.' && bol == 0)
            bol = 1;
        if (assign.str[*k] == '#' && bol > 0) {
            case_1(assign);
            my_putchar('d');
            return (84);
        }
        *k += 1;
    }
    return (0);
}

void case_1(between_t assign)
{
    int bol = 0;

    my_putchar('%');
    for (int k = 0; assign.str[k]; k++) {
        if (assign.str[k] >= '0' && assign.str[k] <= '9') {
            my_put_nbr(assign.str[k] - 48);
            k++;
        } else if (assign.str[k] == '.'
        && (assign.str[k + 1] < '0' || assign.str[k + 1] > '9') && bol == 0) {
            my_putstr(".0");
            k++;
            bol = 1;
        }
        my_putchar(assign.str[k]);
    }
}

int ind_reco(char *str, int *i)
{
    if (str[*i] < 32 || str[*i] >= 127) {
        my_putchar(92);
        my_putnbr_base(str[*i], 8, 87, 1);
        *i += 1;
        if (str[*i] == '\0')
            return (3);
        } else
            my_putchar(str[*i]);
    return (0);
}

int my_put_nbr_spe(int nb, between_t assign, int recup)
{
    int number_mod = nb;
    int number_div;

    if (put_more(assign, nb, recup) == 84)
        return (0);
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    } else if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb >= 10) {
        number_mod = nb % 10;
        number_div = nb / 10;
        my_put_nbr(number_div);
        nb = number_mod;
    }
    my_putchar(nb + 48);
    return (0);
}
