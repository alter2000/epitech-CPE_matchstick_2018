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
    return write(1, &c, 1);
}

long long int my_putstr(char const *str)
{
    unsigned long long int i = 0;

    if (!str || !*str)
        return 0;
    for (; str[i]; i++)
        my_putchar(str[i]);
    return i;
}

char *my_strdup(char const *src)
{
    char *dest = 0;

    while (!dest)
        dest = malloc((my_strlen(src) + 1) * sizeof(char));
    dest = my_strcpy(dest, src);
    return dest;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!src)
        return dest;
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}
