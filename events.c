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
    if ((*ln > b->len) && my_puts("Error: this line is out of range"))
        return 1;
    return 0;
}

static int enough_matches(board_t *board, int ln, int m)
{
    if (ln > board->len || ln < 1 || m > ln * 2 - 1 || m < 1)
        return 0;
    return (count_matches_line(board->b[ln]) >= m);
}

static int get_user_match(board_t *b, int *m, int *ln)
{
    char *buf;

    my_putstr("Matches: ");
    buf = getl(1);
    if (!buf)
        return -1;
    if (*buf == '0' && my_puts("Error: you have to remove at least one match"))
        return 1;
    *m = my_atoi((const char **)&buf);
    if (*m <= 0 && my_puts("Error: invalid input (positive number expected)"))
        return 1;
    if (*m > b->stnum && my_printf("Error: you cannot remove"
                " more than %d matches per turn\n", *m))
        return 1;
    if (!enough_matches(b, *ln, *m) && \
            my_puts("Error: not enough matches on this line"))
        return 1;
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
    return 1;
}

int events(board_t *board, bool *user)
{
    int line;
    int match;

    if (*user) {
        if (get_user(board, &line, &match) && my_printf("Player removed %d "
                    "match(es) from line %d\n", match, line)) {
            (*user) = !(*user);
            return mod_board(board, line, match);
        } else
            return 0;
    } else {
        (*user) = !(*user);
        return ai_play(board);
    }
}
