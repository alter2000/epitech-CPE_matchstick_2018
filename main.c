/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2018
** File description:
** something small
*/

#include "mast.h"

int main(int ac, char **av)
{
    int lines;
    int turn;

    if (ac != 3) {
        my_puts("arguments?");
        return 84;
    }
    lines = my_atoi((char const **)&av[1]);
    turn = my_atoi((char const **)&av[2]);
    if (!(lines > 0 && lines < 100) || !(turn > 0)) {
        my_puts("Invalid board size or turn number");
        return 84;
    }
    return mstick(lines, turn);
}
