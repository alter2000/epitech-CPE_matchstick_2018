/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** something small
*/

#include "mast.h"

static int get_user(board_t *board, char opt)
{
    int res = my_putstr(opt == 'l' ? "Line: " : "Matches: ");
    char *buf = getl(1);

    if (!buf)
    res = my_atoi((const char **)&buf);
    free(buf);
    if (opt == 'l') {
        if (!(res > 0 && res < board->len)) {
            my_putstr("Error: this line is out of range\n");
            return get_user(board, 'l');
        } else
            return res;
    } else
        if (!(res > 0 && res < board->stnum)) {
            my_printf("Error: you cannot remove more than %d matches "
                        "per turn\n", res);
            return get_user(board, 'l');
        } else
            return res;
}

int events(board_t *board, bool user)
{
    /* int line; */
    /* int match; */

    /* if (user) { */
    /*     line = get_user(board, 'l'); */
    /*     match = get_user(board, 'm'); */
    /*     return (line && match) ? mod_board(board, line, match) : 0; */
    /* } else */
    /*     return ai_play(board); */
}
