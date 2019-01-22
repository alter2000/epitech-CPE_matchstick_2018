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

static bool needs_pipe(int lines, int maxlen, int x, int y)
{
    if (!(y == 0 || x == 0 || y == lines + 1 || x == maxlen + 1) && \
            (x - (lines + y) < 0 && (lines + y) > maxlen - x + 1))
        return my_printf("num: %d\tx: %d\ty: %d\n", x - lines - y, x, y);
    return false;
}

static board_t *init_board(int lines, int maxlen, int turn)
{
    board_t *b = gib(sizeof(*b));
    char **bd = gib(sizeof(*bd) * (lines + 3));

    for (int i = 0, j = 0; i < (lines + 2); i++, j = 0) {
        bd[i] = gib(sizeof(*bd[i]) * (maxlen + 3));
        for (; j < (maxlen + 2); j++) {
            bd[i][j] = ((i == 0) || (j == 0) || (i == (lines + 1)) \
                    || (j == (maxlen + 1))) ? '*' : ' ';
            bd[i][j] = needs_pipe(lines, maxlen, j, i) ? '|' : bd[i][j];
        }
    }
    b->b = bd;
    b->stnum = turn;
    b->wid = maxlen;
    b->len = lines;
    b->row = 1;
    b->col = 1;
    return b;
}

static void draw_board(board_t *board)
{
    my_show_word_array((const char **)board->b);
    my_putstr("\n");
}

int mstick(int lines, int turn)
{
    int sticks = get_sticks_line(lines);
    board_t *board = init_board(lines, (lines * 2) - 1, turn);
    bool user = false;
    int evret;

    while (sticks >= 1) {
        draw_board(board);
        evret = events(board, user);
        if (!evret)
            break;
        else
            sticks -= evret;
        if (sticks < 1)
            my_putstr("boi tf is u doin\n");
    }
    return (user) ? 0 : 0;
}
