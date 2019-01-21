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

    for (uint_t i = 0; str && str[i] && \
            (my_isdigit(str[i]) || my_isalpha(str[i])); i++)
        letters++;
    return letters;
}

static int count_words(char const *str)
{
    int words = 0;

    for (uint_t i; str && str[i]; i++)
        if (!my_isalpha(str[i]) && my_isalpha(str[i - 1]))
            words++;
    return words;
}

char **my_str_to_word_array(char const *str)
{
    int words = count_words(str);
    char **arr;
    int letters = count_letters(str);
    int word = 0;
    int i = 0;

    if (!str)
        return 0;
    arr = gib(sizeof(*arr) * (words + 1));
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
    uint_t i = 0;

    for (; tab[i] && *tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return i;
}

void free_array(char **m)
{
    uint_t i = 0;

    for (; m[i]; i++)
        free(m[i]);
    free(m[i]);
    free(m);
}
