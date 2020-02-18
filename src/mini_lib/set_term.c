/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <term.h>
#include <stdio.h>

void verify_term(char *term)
{
    int err = 0;

    if (setupterm(term, 1, &err) < 0) {
        exit(84);
    }
}
