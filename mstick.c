/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** something small
*/

#include "mast.h"

static int get_sticks_line(int lines)
{
    int sticks = 0;

    for (int i = 1; i <= lines; i++)
        sticks += (i * 2) - 1;
    return sticks;
}

static char needs_pipe(int lines, int maxlen, int x, int y)
{
    if (y == 0 || x == 0 || y == lines + 1 || x == maxlen + 1)
        return '*';
    else if ((x - (lines + y) < 0 && (lines + y) > maxlen - x + 1))
        return '|';
    else
        return ' ';
}

static board_t *init_board(int lines, int maxlen, int turn)
{
    board_t *b = gib(sizeof(*b));
    char **bd = gib(sizeof(*bd) * (lines + 3));

    for (int i = 0, j = 0; i < (lines + 2); i++, j = 0)
        for (bd[i] = gib(sizeof(*bd[i]) * (maxlen + 3)); j < maxlen + 2; j++)
            bd[i][j] = needs_pipe(lines, maxlen, j, i);
    b->b = bd;
    b->stnum = turn;
    b->wid = maxlen;
    b->len = lines;
    b->total = get_sticks_line(lines);
    return b;
}

static void draw_board(board_t *board)
{
    my_show_word_array((const char **)board->b);
    my_puts("");
}

int mstick(int lines, int turn)
{
    board_t *board = init_board(lines, (lines * 2) - 1, turn);
    bool user = true;
    int evret;

    draw_board(board);
    while (board->total >= 1) {
        evret = events(board, &user);
        if (evret == 0)
            return 0;
        board->total -= evret;
        draw_board(board);
    }
    return loss(user);
}
