/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2018
** File description:
** something small
*/

#ifndef MAST_H
#define MAST_H

#include "my.h"

typedef struct {
    int total;
    int stnum;
    int len;
    int wid;
    int last;
    char **b;
} board_t;

int mstick(int, int);

int events(board_t *, bool *);
int mod_board(board_t *, int, int);
int ai_play(board_t *);

int count_matches_line(char *);
int loss(bool);
#endif
