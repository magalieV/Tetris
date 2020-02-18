/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

bool verify_is_arg_is_need(bool need_arg, char const *str, char *av)
{
    if (str[0] && str[0] != '-' && !need_arg) {
        help(av);
        exit(84);
    } else if (str[0] && str[0] != '-' && need_arg) {
        return (false);
    }
    if (str[0] && str[0] == '-' && (!str[2] || str[2] == '\0')
    && str[2] != 'h' && str[2] != 'w' && str[2] != 'D') {
        return (true);
    }
    return (need_arg);
}

void verify_if_arg(char *my_arg, int result, char *str)
{
    if (result > 0 && my_arg && my_arg[0] == '\0' && result != 'h'
    && result != 'w' && result != 'D') {
        help(str);
        exit(84);
    }
    if (result > 0 && result != 'm' && my_str_len(my_arg) >= 2) {
        help(str);
        exit(84);
    }
}

void affect_d_option(char res, char *my_arg, my_key_t *my_key)
{
    if (res == 'd')
        my_key->my_pad.key_drop = my_arg[0];
}

void destroy_multi_tab(char **tab)
{
    if (!tab)
        return;
    if (!*tab) {
        free(tab);
        return;
    }
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int check_arg(char **av)
{
    int result = 0;

    for (int i = 1; av[i]; i++) {
        result = check_if_arg_exist(av[i], av[0]);
        if (result == 0) {
            write(2, "Invalid command\n", 16);
            return (84);
        } else if (result == 2) {
            return (2);
        }
    }
    return (0);
}
