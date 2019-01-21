/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** essential functions
*/

#include "my.h"

unsigned long long int my_strlen(char const *str)
{
    unsigned long long int i = 0;

    while (str && str[i])
        i++;
    return i;
}

int my_putchar(int const c)
{
    if (!c)
        return 0;
    return write(STDOUT_FILENO, &c, 1);
}

long long int my_putstr(char const *str)
{
    return write(STDOUT_FILENO, str, my_strlen(str));
}

char *my_strdup(char const *src)
{
    return my_strcpy(gib((my_strlen(src) + 1) * sizeof(char)), src);
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    if (!src)
        return dest;
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}
