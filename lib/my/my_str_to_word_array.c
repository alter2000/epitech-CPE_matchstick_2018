/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** change string to word array
*/

#include <stdlib.h>
#include "my.h"

static int count_letters(char const *str)
{
    unsigned int letters = 0;

    for (uint_t i = 0; str[i] && \
            (my_isdigit(str[i]) || my_isalpha(str[i])); i++)
        letters++;
    return letters;
}

static int count_words(char const *str)
{
    int words = 0;

    for (uint_t i; str[i]; i++)
        if (!my_isalpha(str[i]) && my_isalpha(str[i - 1]))
            words++;
    return words;
}

char **my_str_to_word_array(char const *str)
{
    int words = count_words(str);
    char **arr = gib(sizeof(*arr) * (words + 1));
    int letters = count_letters(str);
    int word = 0;
    int i = 0;

    for (uint_t j = 0; str[j]; j++, i++, word = 0) {
        arr[i] = gib(letters * sizeof(*arr[i]));
        while (my_isspace(str[j]))
            j++;
        while (my_isalpha(str[j]) || my_isdigit(str[j]))
            arr[i][word++] = str[j++];
    }
    arr[i] = 0;
    return arr;
}

int my_show_word_array(char const *tab[])
{
    int res = 0;

    for (uint_t i = 0; tab && tab[i]; i++) {
        res += my_putstr(tab[i]);
        res += my_putchar('\n');
    }
    return res;
}

void free_array(char **m)
{
    uint_t i = 0;

    for (; m[i]; i++)
        free(m[i]);
    free(m[i]);
    free(m);
}
