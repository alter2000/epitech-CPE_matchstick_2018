/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** modified functions for printf
*/

#include "../my.h"
#include "my_printf.h"

unsigned int p_bin(unsigned int flags, unsigned int width, \
        unsigned int precision, va_list arg)
{
    flags &= ~F_HASH;
    if (flags & F_LLONG)
        return p_putnbr(va_arg(arg, long long), "01", width);
    if (flags & F_LONG)
        return p_putnbr(va_arg(arg, long), "01", width);
    if (flags & F_CHAR)
        return p_putnbr((char) va_arg(arg, int), "01", width);
    if (flags & F_SHORT)
        return p_putnbr((short int) va_arg(arg, int), "01", width);
    return p_putnbr(va_arg(arg, int), "01", width);
}
