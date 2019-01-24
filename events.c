/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** something small
*/

#include "mast.h"

static int get_user_line(board_t *b, int *ln)
{
    char *buf;

    my_putstr("Line: ");
    buf = getl(1);
    if (!buf)
        return -1;
    *ln = my_atoi((const char **)&buf);
    if (*ln < 1 && my_puts("Error: invalid input (positive number expected)"))
        return 1;
    if ((*ln > b->len) && my_putnbr(b->len) && my_puts("Error: this line is out of range"))
        return 1;
    return 0;
}

static int enough_matches(board_t *board, int ln, int m)
{
    int mnum = 0;

    if (ln > board->len || ln < 1 || m < ln * 2 - 1 || m < 1)
        return 0;
    for (int i = 0; board->b[ln] && board->b[ln][i]; i++)
        mnum += (board->b[ln][i] == '|');
    return (mnum >= m);
}

static int get_user_match(board_t *b, int *m, int *ln)
{
    char *buf;

    my_putstr("Matches: ");
    buf = getl(1);
    if (!buf)
        return -1;
    if (*buf == '0' && my_puts("Error: you have to remove at least one "
                "match\n"))
        return 1;
    *m = my_atoi((const char **)&buf);
    if (*m <= 0 && my_puts("Error: invalid input (positive number expected)"))
        return 1;
    if (*m > b->stnum && my_printf("Error: you cannot remove"
                " more than %d matches per turn\n", *m))
        return 1;
    if (!enough_matches(b, *ln, *m))
    {
            my_puts("Error: not enough matches on this line");
        return 1;
    }
    return 0;
}

static int get_user(board_t *board, int *ln, int *mat)
{
    int ret = 0;

    my_puts("Your turn:");
    while (1) {
        ret = get_user_line(board, ln);
        if (1 == ret)
            continue;
        if (-1 == ret)
            return 0;
        ret = get_user_match(board, mat, ln);
        if (1 == ret)
            continue;
        if (-1 == ret)
            return 0;
        if (0 == ret)
            break;
    }
}

int events(board_t *board, bool user)
{
    int line;
    int match;

    if (user) {
        return (get_user(board, &line, &match)) ? \
                mod_board(board, line, match) : 0;
    } else
        return ai_play(board);
}