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
