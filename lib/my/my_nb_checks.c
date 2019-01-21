/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** number calc
*/

#include "my.h"

int my_is_prime(int const nb)
{
    int prime = 1;

    if (nb <= 1)
        return 0;
    for (int i = 2; i <= (nb / 2); i++) {
        if (nb % i == 0) {
            prime = 0;
            break;
        }
    }
    return prime;
}

int my_count_digits_rec(int const n, int const i)
{
    if (n < INT_MIN || n > INT_MAX) {
        write(2, "count_digits: number out of bounds\n", 35);
        return 84;
    }
    if (n / 10 != 0)
        return i + my_count_digits_rec(n / 10, i);
    else if (n >= 0)
        return 1;
    else
        return 0;
}

int my_count_digits(int const n)
{
    return my_count_digits_rec((n >= 0) ? n : -n, 0);
}
