/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf main file
*/

#include "../my.h"
#include "my_printf.h"

int my_printf(char const *fmt, ...)
{
    va_list ap;
    int chars;

    va_start(ap, fmt);
    chars = pstuff(fmt, ap);
    va_end(ap);
    return chars;
}

int pstuff(char const *fmt, va_list ap)
{
    unsigned int ch = 0;

    for (unsigned int flag = 0, chk = 0, prec = 0, width = 0; *fmt;) {
        if (*fmt != '%') {
            ch += my_putchar(*fmt++);
            continue;
        } else
            fmt++;
        do {
            chk = set_flags(*fmt, &flag);
            fmt += chk;
        } while (chk);
        width = my_isdigit(*fmt) ? my_atoi(&fmt) : 0;
        if (*fmt == '.') {
            prec = (my_isdigit(*++fmt)) ? my_atoi(&fmt) : 0;
        }
        ch += put(setlen(&fmt, &flag), *fix_flags(&flag), width, prec, ap);
    }
    return ch;
}

unsigned int more_extended_put(char const **fmt, va_list ap)
{
    unsigned int ch = 0;

    switch (**fmt) {
        case 'S': ++(*fmt);
                ch += p_showstr(va_arg(ap, char *));
                break;
        case 'p': ++(*fmt);
                ch += p_showptr(va_arg(ap, size_t));
                break;
        case '%': ++(*fmt);
                ch += my_putchar('%');
                break;
        default: ch += my_putchar('%');
                ch += my_putchar(*(++(*fmt)));
                break;
    }
    return ch;
}

unsigned int extended_put(char const **fmt, unsigned int flags, \
        unsigned int width, unsigned int prec, va_list ap)
{
    unsigned int ch = 0;

    switch (**fmt) {
        case 'o': ++(*fmt);
                ch += p_oct(flags, width, prec, ap);
                break;
        case 'b': ++(*fmt);
                ch += p_bin(flags, width, prec, ap);
                break;
        case 'c': ++(*fmt);
                ch += my_putchar((char) va_arg(ap, int));
                break;
        case 's': ++(*fmt);
                ch += p_putstr(va_arg(ap, char *), flags, width);
                break;
        default: ch += more_extended_put(fmt, ap);
    }
    return ch;
}

unsigned int put(char const **fmt, unsigned int flags, \
        unsigned int width, unsigned int prec, va_list ap)
{
    unsigned int ch = 0;

    switch (**fmt) {
        case 'd': case 'i': ++(*fmt);
                ch += p_dec(flags, width, prec, ap);
                break;
        case 'u': ++(*fmt);
                ch += p_udec(flags, width, prec, ap);
                break;
        case 'x': ++(*fmt);
                ch += p_hex(flags, width, prec, ap);
                break;
        case 'X': ++(*fmt);
                ch += p_chex(flags, width, prec, ap);
                break;
        default: ch += extended_put(fmt, flags, width, prec, ap);
    }
    return ch;
}
