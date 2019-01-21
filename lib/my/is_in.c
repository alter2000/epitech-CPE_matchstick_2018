/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** like Python `in' operator
*/

#include "my.h"

int is_in(char const elem, char const *set)
{
    for (unsigned int i = 0; set[i]; i++)
        if (set[i] == elem)
            return 1;
    return 0;
}

char *my_strstr(char *str, const char *to_find)
{
    if (!*str)
        return 0;
    if (!*to_find)
        return str;
    if ((*str == *to_find) && (!my_strcmp(str, to_find)))
        return str;
    return my_strstr(str + 1, to_find);
}

int my_isspace(char const ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\v' \
            || ch == '\r' || ch == '\n');
}
