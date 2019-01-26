/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** something small
*/

#include "mast.h"

int count_matches_line(char *line)
{
    int m = 0;

    for (int i = 0; line && line[i]; i++)
        m += (line[i] == '|');
    return m;
}

int loss(bool user)
{
    if (user) {
        my_puts("You lost, too bad...");
        return 2;
    } else {
        my_puts("I lost... snif... but I'll get you next time!!");
        return 1;
    }
}
