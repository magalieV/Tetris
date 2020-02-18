/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#ifndef INIT_OPT
#define INIT_OPT
#include <getopt.h>

const char SHORTS_OPTION[] = "hL:l:r:t:d:q:p:wD";

const struct option LONGS_OPTION[] = {
    {"help", no_argument, NULL, 'h'},
    {"level", optional_argument, NULL, 'L'},
    {"key-left", optional_argument, NULL, 'l'},
    {"key-right", optional_argument, NULL, 'r'},
    {"key-turn", optional_argument, NULL, 't'},
    {"key-drop", optional_argument, NULL, 'd'},
    {"key-quit", optional_argument, NULL, 'q'},
    {"key-pause", optional_argument, NULL, 'p'},
    {"map-size", optional_argument, NULL, 'm'},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {NULL, 0, NULL, 0},
};

#endif
