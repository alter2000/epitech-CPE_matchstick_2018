/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf header file
*/

#ifndef MY_PRINTF_H
#    define MY_PRINTF_H

#    include <stdarg.h>

/* like UNIX permissions weeeee */
#    define F_HASH  (1U <<  0U)
#    define F_ZERO  (1U <<  1U)
#    define F_LEFT  (1U <<  2U)
#    define F_SPACE (1U <<  3U)
#    define F_PLUS  (1U <<  4U)

#    define F_UPPER (1U <<  5U)
#    define F_CHAR  (1U <<  6U)
#    define F_SHORT (1U <<  7U)
#    define F_LONG  (1U <<  8U)
#    define F_LLONG (1U <<  9U)

#    define START_BITMASK_SWITCH(x) \
    for (size_t bit = 1; bit <= x; bit <<= 1) switch (bit)

// my_printf.c
int my_printf(char const *, ...);

int pstuff(char const *, va_list);
unsigned int put(char const **, unsigned int, \
        unsigned int, unsigned int, va_list);

char const **setlen(char const **, unsigned int *);
void check_ptr(char const **, unsigned int *);
int set_flags(char, unsigned int *);
unsigned int *fix_flags(unsigned int *);

unsigned int p_putnbr(long long int, char const * const, int const);
unsigned int p_uputnbr(unsigned long long int, char const * const, int const);
unsigned int p_showstr(char const *);
unsigned int p_showptr(long long int);
unsigned int p_putstr(char const *, unsigned int, unsigned int);

unsigned int p_dec(unsigned int, unsigned int, unsigned int, va_list);
unsigned int p_udec(unsigned int, unsigned int, unsigned int, va_list);

unsigned int p_hex(unsigned int, unsigned int, unsigned int, va_list);
unsigned int p_chex(unsigned int, unsigned int, unsigned int, va_list);

unsigned int p_oct(unsigned int, unsigned int, unsigned int, va_list);
unsigned int p_bin(unsigned int, unsigned int, unsigned int, va_list);

#endif // MY_PRINTF_H
