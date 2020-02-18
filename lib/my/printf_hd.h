/*
** EPITECH PROJECT, 2018
** include for printf
** File description:
** include for printf
*/

#ifndef PRINT
#define PRINT

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct between {
    char *str;
    int space;
} between_t;

typedef struct line {
    int bol;
    int recup;
    int size;
} line_t;

char *my_strdup_print(char *str);

void decim_assign(int, between_t);

void my_put_nbr_u(unsigned int);
void my_putchar(char);
int my_putstr(char *);
int my_put_nbr(int);
void attribut_space(between_t, int, char, int);

int get_nbr(between_t, int *);
void case_1(between_t);
int flag_double(va_list, char, between_t);
int ind_reco(char *, int *);

void my_putnbr_base(unsigned int, int, int, int);
void my_putnbr_base_long(unsigned long, int, int);

int found_assign_str(char);
int found_flag(char);
int count_size(char *);

int my_getnbr(char const *);
int my_strlen(char *);
int my_strlen_nb(int *);

int my_printf(char const *, ...);
int get_number(char const);
between_t found_number(char *, int, int *);

int sort_sring_attribut(char *, between_t);
void put_zero(int *, int);
int decim_recup(int, int, int, between_t);
int size_decim(int);
int decim_flag_f(between_t, int, int);

int found_attribut(char);
int non_printable_string(char *);

int put_more(between_t, int, int);
int my_put_nbr_spe(int, between_t, int);

unsigned int size_decim_u(unsigned int);
void attribut_space_u(between_t, unsigned, char, int);

int found_more_less(char *);
void secu_str(char *);
void test_secu(int *, int *, char, char);

char *alloc_mem(char *);
int sepa_one(char, va_list, between_t);
between_t sepa_two(char const *, int *, int *);
int found_flag_less(between_t, int);
void put_space(between_t);
int found_flag_point(between_t, int);

#endif
