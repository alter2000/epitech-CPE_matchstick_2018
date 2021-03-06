/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** something small
*/

#include "mast.h"

static int get_smallest_fitting_line(char **b, int max)
{
    int smidx = 0;

    if (max <= 0)
        return 0;
    for (int i = 1, ctmp = INT_MAX, cur = 0; b && b[i]; i++) {
        cur = count_matches_line(b[i]);
        if (cur < ctmp && cur >= max) {
            smidx = i;
            ctmp = cur;
        }
    }
    return smidx;
}

static int get_ai_coords(board_t *b, int *m)
{
    int ln = 0;

    *m = b->stnum - b->last;
    if (*m <= 0)
        *m = 1;
    while (*m > b->total)
        (*m)--;
    (*m)++;
    while (!ln && *m > 0) {
        (*m)--;
        if (b->total - *m == 0 && b->total != 1)
            (*m)--;
        ln = get_smallest_fitting_line(b->b, *m);
        if (b->total - *m < 0)
            ln = 0;
    }
    return ln;
}

int mod_board(board_t *b, int line, int mat)
{
    int idx = 1;

    for (; b->b[line][idx] == ' '; idx++);
    for (; b->b[line][idx] == '|'; idx++);
    idx--;
    for (int cnt = mat; cnt > 0 && idx > 0; idx--, cnt--)
        b->b[line][idx] = ' ';
    b->last = mat;
    return mat;
}

int ai_play(board_t *b)
{
    int ret;
    int mat;
    int ln = get_ai_coords(b, &mat);

    my_puts("AI's turn...");
    ret = mod_board(b, ln, mat);
    my_printf("AI removed %d match(es) from line %d\n", mat, ln);
    return ret;
}
