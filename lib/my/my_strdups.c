/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** concatenate two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    for (; src[i]; i++)
        dest[i + len] = src[i];
    dest[i + len] = 0;
    return dest;
}

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    char *len = dest + my_strlen(dest);

    for (; src[i] && i < n; i++)
        len[i] = src[i];
    len[i] = 0;
    return dest;
}

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return 0;
    while (*s1 && *s2) {
        if (*s1 == *s2)
            return my_strcmp((s1 + 1), (s2 + 1));
        else
            return *s1 - *s2;
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (!s1 || !s2 || n)
        return 0;
    while (*s1 && *s2 && n) {
        if (*s1 == *s2)
            return my_strncmp((s1 + 1), (s2 + 1), n - 1);
        else
            return s1 - s2;
    }
    return -1;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!src || n < 1)
        return 0;
    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    if (i > n)
        dest[i] = '\0';
    return dest;
}
