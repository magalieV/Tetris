/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** SEPARATION_FLAG
*/

#ifndef SEPA
#define SEPA

void hexa_assign(unsigned int, between_t, char);
void unsign_dec(unsigned int, between_t, char);
void binar_unsign(unsigned int, between_t, char);
void octal_assign(unsigned int, between_t, char);

typedef struct separ {
    char flag;
    void (*sort)(unsigned int, between_t, char);
} separ_t;

const separ_t SEPARATION_TAB[] = {
    {'o', &octal_assign},
    {'x', &hexa_assign},
    {'X', &hexa_assign},
    {'u', &unsign_dec},
    {'b', &binar_unsign},
    {'\0', NULL}};

#endif
