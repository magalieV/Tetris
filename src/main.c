/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "header.h"

void help(char *av)
{
    my_printf("Usage:  %s [options]\n", av);
    my_printf("Options:\n");
    my_printf(" --help               Display this help\n");
    my_printf(" -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_printf(" -l --key-left={K}    Move the tetrimino LEFT using the K key");
    my_printf(" (def: left arrow)\n -r --key-right={K}   Move the tetrimino");
    my_printf(" RIGHT using the K key (def: right arrow)\n -t --key-turn={K}");
    my_printf("    TURN the tetrimino clockwise 90d using the K key");
    my_printf(" (def: toparrow)\n -d --key-drop={K}    DROP the tetrimino");
    my_printf(" using the K key (def: down arrow)\n -q --key-quit={K}    QUIT");
    my_printf(" the game using the K key (def: 'q' key)\n -p --key-pause={K}");
    my_printf("   PAUSE/RESTART the game using the K key (def: space bar)\n");
    my_printf(" --map-size={row,col} Set the numbers of rows and columns of");
    my_printf(" the map (def: 20,10)\n -w --without-next    Hide next");
    my_printf(" tetrimino (def: false)\n -D --debug");
    my_printf("           Debug mode (def: false)\n");
}

char *copy_without_slash(char const *str)
{
    int i = 2;
    bool stop = false;

    if (!str)
        return (NULL);
    char *new = malloc(sizeof(char) * (my_str_len((char *)str) + 1));
    if (!new)
        return (NULL);
    while (str[i] && str[i] != '=') {
        new[i - 2] = str[i];
        i++;
    }
    new[i - 2] = '\0';
    return (new);
}

void destroy_my_list(object_t *object)
{
    while (object && object->prev)
        object = object->prev;
    while (object) {
        if (object->next == NULL)
            break;
        object = object->next;
        if (object->prev->name)
            free(object->prev->name);
        if (object->prev->shem)
            destroy_multi_tab(object->prev->shem);
        free(object->prev);
    }
    if (object->name)
        free(object->name);
    if (object->shem)
        destroy_multi_tab(object->shem);
    free(object);
}

static void next_of_game(bool debug_mode_activate, my_key_t my_key)
{
    char *tmp = NULL;

    if (debug_mode_activate) {
        display_debug_mode(my_key);
        my_printf("Press any key to start Tetris\n");
        while ((tmp = get_next_line(0)) == NULL);
    }
    if (tmp)
        free(tmp);
    display_game(my_key);
    destroy_my_list(my_key.object);
}

int main(int ac, char **av, char **env)
{
    my_key_t my_key = {0};
    int result = 0;
    bool debug_mode_activate = false;
    char *term = NULL;

    if (!env || !*env) {
        help(av[0]);
        return (84);
    }
    term = get_env(env, "TERM");
    verify_term(term);
    srand(time(NULL));
    my_key = init_my_key(av);
    if (ac >= 2)
        result = check_arg(av);
    if (result != 0) {
        return (result == 84 ? 84 : 0);
    }
    debug_mode_activate = modify_key(av, ac, &my_key);
    next_of_game(debug_mode_activate, my_key);
    return (0);
}
