/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"
#include "init_option_hd.h"

static void check_if_already_use(char letter, my_key_t *my_key, char *av)
{
    if (letter == my_key->my_pad.key_left ||
    letter == my_key->my_pad.key_right || letter == my_key->my_pad.key_turn) {
        help(av);
        exit(84);
    }
    if (letter == my_key->my_pad.key_drop || letter == my_key->my_pad.key_quit
    || letter == my_key->my_pad.key_quit) {
        help(av);
        exit(84);
    }
}

static void check_key(char res, char *my_arg, my_key_t *my_key, char *av)
{
    switch (res) {
        case 'h':
            help(av);
            break;
        case 'L':
            my_key->level = my_getnbr(my_arg);
            break;
        case 'l':
            my_key->my_pad.key_left = my_arg[0];
            break;
        case 'r':
            my_key->my_pad.key_right = my_arg[0];
            break;
        case 't':
            my_key->my_pad.key_turn = my_arg[0];
            break;
        default:
            affect_d_option(res, my_arg, my_key);
            break;
    }
}

static bool check_other_option(char res, char *my_arg, char **tmp,
    my_key_t *my_key)
{
    switch (res) {
        case 'q':
            my_key->my_pad.key_quit = my_arg[0];
            break;
        case 'p':
            my_key->my_pad.key_pause = my_arg[0];
            break;
        case 'm':
            set_size_map(tmp, my_key);
            break;
        case 'w':
            my_key->next = false;
            break;
        case 'D':
            return (true);
            break;
        default:
            break;
    }
    return (false);
}

int check_if_arg_exist(char const *str, char *av)
{
    int size = 0;
    char *tmp = NULL;
    static bool need_arg = false;

    need_arg = verify_is_arg_is_need(need_arg, str, av);
    if (str[0] && str[0] == '-' && str[1] && str[1] == '-') {
        if (my_strncmp(str, "--help") == 0 || my_strncmp(str, "-h") == 0) {
            help(av);
            return (2);
        }
        for (int i = 0; LONGS_OPTION[i].name; i++) {
            tmp = copy_without_slash(str);
            if (my_strncmp(LONGS_OPTION[i].name, tmp) == 0)
                size++;
            (my_strncmp(tmp, "without-next") != 0
            && my_strncmp(tmp, "debug") != 0) ? found_equal(str, av) : 0;
            free(tmp);
        }
    } else
        return (1);
    return (size == 1 ? 1 : 0);
}

bool modify_key(char **av, int ac, my_key_t *my_key)
{
    char *my_arg = NULL;
    char **tmp = NULL;
    bool debug_mode_activate = false;
    bool temp = false;
    int result = 0;

    while ((result = getopt_long(ac, av, SHORTS_OPTION,
    LONGS_OPTION, NULL)) != -1) {
        my_arg = optarg;
        verify_if_arg(my_arg, result, av[0]);
        if (my_arg)
            tmp = my_str_to_word_array(my_arg, "\n ,");
        if (my_arg && my_arg[0] != '\0')
            check_if_already_use(my_arg[0], my_key, av[0]);
        check_key(result, my_arg, my_key, av[0]);
        temp = check_other_option(result, my_arg, tmp, my_key);
        if (temp)
            debug_mode_activate = true;
    }
    return (debug_mode_activate);
}
