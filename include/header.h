/*
** EPITECH PROJECT, 2019
** s
** File description:
** s
*/

#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>
#include <grp.h>
#include <errno.h>
#include <ncurses.h>

#ifndef READ_SIZE
#define READ_SIZE 128
#endif

typedef struct pad {
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
} pad_t;

typedef struct map {
    int x;
    int y;
} map_t;

typedef struct object {
    bool ok_or_ko;
    char *name;
    int x;
    int y;
    int color;
    char **shem;
    struct object *next;
    struct object *prev;
} object_t;

typedef struct my_key {
    pad_t my_pad;
    bool next;
    int level;
    map_t my_map;
    object_t *object;
    int size_object;
} my_key_t;

typedef struct my_pos {
    int x;
    int y;
} my_pos_t;

typedef struct my_game {
    int level;
    int time;
    int score;
    int lines;
    int hight_score;
    int save;
    int line;
    int speed;
    my_pos_t pos;
    my_key_t key;
} my_game_t;

my_key_t init_my_key(char **);
void display_debug_mode(my_key_t my_key);
char **my_str_to_word_array_up(char const *str, char *param);
char **read_doub_file(char const *str);
object_t *init_object(my_key_t *key);
char *get_next_line(int fd);
int my_strncmp(char const *sa, char const *sb);
char **my_str_to_word_array(char const *str, char *param);
int my_getnbr(char const *str);
char *copy_without_slash(char const *str);
int check_arg(char **av);
bool modify_key(char **av, int ac, my_key_t *my_key);
void help(char *);
int check_if_arg_exist(char const *str, char *);
void display_key_info(char const *str, int key);
void print_my_tetriminos(my_key_t my_key);
int my_printf(char const *str, ...);
object_t *sort_list_object(object_t *my_object);
bool if_end_of_name(char const *str, int i);
int my_str_len(char *str);
bool if_color_exist(int color);
bool too_much_information(char **str);
bool bad_char_on_file(char **str);
void destroy_multi_tab(char **tab);
void verify_term(char *term);
void set_size_map(char **tmp, my_key_t *my_key);

char *my_strdup_print(char *str);
int my_getnbrr(char const *str);
char *concat_my_path_terminos(char *str);
char *remove_type_path(char *path);
object_t *check_info_file(char const *path, object_t *begin);

char *get_env(char *const *env, char const *path_search);

//PARSING TETRIMINOS
object_t *change_next_and_prev(object_t *, object_t *);
bool if_number_is_ok(char **);
char **recup_buffer(char const *);
object_t *init_my_object(char const *, object_t *, object_t *);
object_t *fill_my_number(char **, object_t *);

//SECURITY TETRIMINOS
object_t *init_my_shem(char **, object_t *);
bool check_size_tetrimino(int, int, int, int);
int size_of_information(void);
object_t *create_object(DIR *, my_key_t *, object_t *);

//SECURITY
void affect_d_option(char, char *, my_key_t *);
void verify_if_arg(char *, int, char *);
bool verify_is_arg_is_need(bool, char const *, char *);

//SECURITY COLOR
void found_equal(char const *, char *);

//GAME
void display_game(my_key_t);
void init_key_for_game(my_key_t *my_key);
void pos_piece(my_pos_t *pos, char **tab, int x);
void display_map(char **tab);
char **init_map_graph(int x, int y);
int my_tab_len(char **tab);
object_t *size_correspond(object_t *object);
void init_game_element(my_key_t my_key, my_game_t *game);
char **moove_piece_to_left(char **tab);
void my_init_color(void);
int init_window(void);

//number_to_string
char *number_to_string(int);

//DATA_MANAGE
bool up_time(clock_t, my_game_t *);
void display_game_map(char **, object_t **, my_game_t);
bool up_hight_score(my_game_t *);
char **key_is_press(my_key_t, my_pos_t *, char **, int *);
bool fall_piece(clock_t, int *, float);

//DISPLAY
void display_board(my_game_t);
void display_piece(char **, my_pos_t, int, char **);
void display_next(char **, int);
char *display_piece_color(int, char, bool, char *);

//INIT_KEY_GRAPH
void my_init_color(void);

//CHOOSE_TETRIMINOS
object_t *choose_random_tetri(my_key_t);
bool on_line(char **, char **, my_pos_t, int);
char **concat_map_and_piece(char **, char **, my_pos_t, int);
bool line_entire(char **, int *, int *);
char **suppr_line(char **tab, int line);

//INIT_TETRI
object_t **init_tetriminos_and_game(my_key_t *, my_game_t *);
void event_of_game(my_game_t *game, char **map, object_t **tetriminos);
char **delete_line(char **map, my_game_t *game, object_t **tetriminos);
char **concat_element(char **map, object_t **tetriminos, my_game_t *game);
void pause_loop(my_key_t key);

#endif
