/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** muh library
*/

#ifndef _MY_H_
#    define _MY_H_

#    include <fcntl.h>
#    include <limits.h>
#    include <stdarg.h>
#    include <stdbool.h>
#    include <stddef.h>
#    include <stdio.h>
#    include <stdlib.h>
#    include <sys/types.h>
#    include <unistd.h>

#    ifndef READ_SIZE
#        define READ_SIZE (20)
#    endif // READ_SIZE

#    define MIN(i, j) (((i) < (j)) ? (i) : (j))
#    define MAX(i, j) (((i) > (j)) ? (i) : (j))
#    define ABS(i)    (((i) > 0)   ? (i) : -(i))

typedef unsigned long long int ull_t;
typedef unsigned long int ul_t;
typedef unsigned int uint_t;
typedef long long int ll_t;
typedef long int l_t;

struct btree {
    struct btree *left;
    struct btree *right;
    struct btree *parent;
    struct btree *next;
    struct btree *root;
    void *data;
};
typedef struct btree btree_t;

typedef struct node {
    struct node *next;
    struct node *prev;
    void *data;
} node_t;

typedef struct list {
    struct node *first;
    struct node *last;
} list_t;

typedef struct file_desc_s {
    int fd;
    int ridx;
    int rbuflen;
    char rbuf[READ_SIZE + 2];
    struct file_desc_s *next;
} file_desc_t;

btree_t *btree_create_node(char *);
void btree_insert_data(btree_t *, char *, int (*)());
size_t btree_level_count(btree_t const *);
void btree_destroy(btree_t *);

void btree_apply_infix(btree_t *, long long int (*)(char *));
void btree_apply_prefix(btree_t *, long long int (*)(char *));
void btree_apply_postfix(btree_t *root, long long int (*)(char *));

int my_printf(char const *, ...);

unsigned long long int my_strlen(char const *);
int my_putchar(int const);
long long int my_putstr(char const *);
int my_numlen(long long int);
int my_putnbr(int);
int my_putnbr_base(int, char const *);
long long int dysfunctional_my_getnbr(char const *);
long long int dysfunctional_getnbr_rec(char const *, long long int);
long long int my_strtoll(char *, char **, long long int);
int my_atoi(char const **);
long long int my_atoll(char const **);
char *my_itoa(int);

char *my_revstr(char *);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);

int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
void my_showstr(char const *);

char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);

int is_in(char const, char const *);
void my_swap(int *, int *);
void bsort_int(int *, int);

int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);

int my_isdigit(char);
int my_isupper(char);
int my_islower(char);
int my_isalpha(char);
int my_isspace(char);
int my_isprintable(char);

char **my_str_to_word_array(char const *);
int my_show_word_array(char const **);
void free_array(char **);
char *my_strdup(char const *);
void *my_memset(char *, char, size_t);
char *my_realloc(char *, int);
void *gib(size_t);
void *regib(char *, int);

char *getl(int const);
char *getd(int const, int const);

static inline size_t err(char const *errstr)
{
    if (!errstr || !*errstr) {
        write(2, "err: no error string\n", 21);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    return 0;
}

static inline size_t errb(char const *errstr)
{
    if (!errstr || !*errstr) {
        write(2, "errb: no error string\n", 22);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    _exit(84);
}

static inline size_t errc(char *buf, char const *errstr)
{
    if (!errstr || !*errstr || !buf || !*buf) {
        write(2, "errc: no error string or invalid buffer\n", 32);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    free(buf);
    _exit(84);
}

static inline size_t errm(char **buf, char const *errstr)
{
    uint_t i = 0;

    if (!errstr || !buf || !*errstr || !*buf) {
        write(2, "errm: no error string or invalid buffer\n", 32);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    for (; buf[i]; i++) free(buf[i]);
    free(buf[i]);
    free(buf);
    _exit(84);
}

#endif // _MY_H_
