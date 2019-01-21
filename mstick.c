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

static char **init_board(int lines, int maxlen)
{
    char **board = gib(sizeof(*board) * (lines + 3));

    for (int i = 0, j = 0; i < (lines + 2); i++, j = 0) {
        board[i] = gib(sizeof(*board[i]) * (maxlen + 3));
        for (; j < (maxlen + 2); j++)
            board[i][j] = ((i == 0) || (j == 0) || (i == (lines + 1)) \
                    || (j == (maxlen + 1))) ? '*' : ' ';
    }
    return board;
}

static void draw_board(char **board)
{
    my_show_word_array((const char **)board);
}

int mstick(int lines, int turn)
{
    int sticks = get_sticks_line(lines);
    char **board = init_board(lines, (lines * 2) - 1);
    bool user = false;

    while (sticks >= 1) {
        draw_board(board);
        break;
    }
    return (user) ? 0 : 0;
}
