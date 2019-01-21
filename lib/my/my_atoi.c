/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** copy two last functions to program files else always return 0
*/

#include "my.h"

int my_atoi(char const **s)
{
    int nbr = 0;

    if (!s || !*s)
        return 0;
    while (my_isspace(**s))
        s++;
    for (; my_isdigit(**s); (*s)++)
        nbr = nbr * 10 + (**s - '0');
    if (nbr > INT_MAX || nbr < INT_MIN)
        return 0;
    return nbr;
}

long long int my_atoll(char const **s)
{
    long long int nbr = 0;

    if (!s || !*s)
        return 0;
    while (my_isspace(**s))
        (*s)++;
    for (;**s >= '0' && **s <= '9'; (*s)++)
        nbr = nbr * 10 + (**s - '0');
    if (nbr > LLONG_MAX || nbr < LLONG_MIN)
        return 0;
    return nbr;
}

long long int dysfunctional_getnbr_rec(char const *ch, long long int i)
{
    if (i < LLONG_MIN + 10)
        return LLONG_MIN;
    if (i > LLONG_MAX - 10)
        return LLONG_MAX;
    if (*ch && *(ch + 1) \
        && (*ch == '-' && my_isdigit(*(ch + 1))))
        return -dysfunctional_getnbr_rec((ch + 1), i * 10);
    if (*ch && my_isdigit(*ch))
        return dysfunctional_getnbr_rec((ch + 1), i * 10  + (*ch - '0'));
    return i;
}

long long int dysfunctional_my_getnbr(char const *str)
{
    if (!str || (str[0] != '-' && my_isdigit(str[0])))
        return 0;
    return dysfunctional_getnbr_rec(str, 0LL);
}
