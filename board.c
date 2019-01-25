/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** something small
*/

#include "mast.h"

static int get_idx(char const *ln, char opt)
{
    int m = 1;

    for (; ln[m] == ' '; m++);
    if (opt == 'r')
        for (; ln[m] == '|'; m++);
    return m - 1;
}

/* for (int i = 1, min = INT_MAX, mtmp = count_matches_line(b[i]); \
 * b && b[i]; i++) { */
static int get_smallest_fitting_line(char **b, int max)
{
    int smidx = 0;

    for (int i = 1, ctmp = INT_MAX, cur = 0; b && b[i]; i++) {
        cur = count_matches_line(b[i]);
        if (cur < ctmp && cur >= max)
            smidx = i;
    }
    return smidx - 1;
}

int mod_board(board_t *b, int line, int mat)
{
    for (int i = get_idx(b->b[line], 'r'), cnt = mat; \
            cnt > 0 && i > 1; i--, cnt--)
        b->b[line][i] = ' ';
    return mat;
}

int ai_play(board_t *b)
{
    int ret;
    int ln = get_smallest_fitting_line(b->b, b->stnum);
    int mat = 3;

    my_puts("AI's turn...");
    ret = mod_board(b, ln, mat);
    my_printf("AI removed %d match(es) from line %d\n", mat, ln);
    return ret;
}
