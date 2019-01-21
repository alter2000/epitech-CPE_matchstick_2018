/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** print number on stdout + get llong
*/

#include "my.h"

int my_putnbr_base(int nb, char const *base)
{
    int b = my_strlen(base);

    if (nb < INT_MIN || nb > INT_MAX) {
        write(2, "put_nbr: out of bounds\n", 23);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        my_putnbr_base(-nb, base);
    } else if (nb > b - 1) {
        my_putnbr_base(nb / b, base);
        my_putnbr_base(nb % b, base);
    } else
        my_putchar(base[nb]);
    return nb;
}

int my_putnbr(int nb)
{
    return my_putnbr_base(nb, "0123456789");
}

char *my_itoa(int nb)
{
    short sign = (nb < 0);
    char *str = gib(my_numlen(nb) + sign + 1);
    short left = 0;
    unsigned int i = 0;
    nb = (nb < 0) ? -nb : nb;

    do {
        left = nb % 10;
        nb /= 10;
        str[i++] = left + '0';
    } while (nb > 0);
    if (sign)
        str[i++] = '-';
    str[i] = '\0';
    return my_revstr(str);
}

long long int my_strtoll(char *s, char **end, long long int rec)
{
    if (rec < LLONG_MIN)
        return LLONG_MIN;
    if (rec > LLONG_MAX)
        return LLONG_MAX;
    if (*s && *(s + 1) && (*s == '-' && my_isdigit(*(s + 1)))) {
        end++;
        return -my_strtoll((s + 1), end, rec * 10);
    } else if (*s && my_isdigit(*s)) {
        end++;
        return my_strtoll((s + 1), end, rec * 10  + (*s - '0'));
    } else
        return rec;
}
