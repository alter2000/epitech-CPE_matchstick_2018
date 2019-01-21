/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** GNL implementation
*/

#include "my.h"

static file_desc_t *ret_file(int const fd, file_desc_t **f)
{
    file_desc_t *tmp;
    file_desc_t *file_info;

    for (tmp = *f; tmp; tmp = tmp->next)
        if (tmp->fd == fd)
            return tmp;
    file_info = gib(sizeof(*file_info));
    file_info->fd = fd;
    if (!*f) {
        *f = file_info;
    } else {
        for (tmp = *f; tmp && tmp->next; tmp = tmp->next);
        tmp->next = file_info;
    }
    return file_info;
}

static char *append(char *lnbuf, int n, file_desc_t *f)
{
    int oldlen = my_strlen(lnbuf);
    char *newlen = malloc((oldlen + n + 1) * sizeof(*newlen));

    my_strncpy(newlen, lnbuf, oldlen);
    newlen[oldlen + n] = 0;
    my_strncpy(newlen + oldlen, f->rbuf + f->ridx, n);
    if (lnbuf)
        free(lnbuf);
    f->ridx += n + 1;
    return (newlen);
}

static void reread(file_desc_t *f, int *n, int *readret, int fd)
{
    f->ridx = 0;
    *n = 0;
    *readret = read(fd, f->rbuf, READ_SIZE);
}

char *getd(const int fd, const int ch)
{
    static file_desc_t *all_f;
    static int readret = 0;
    file_desc_t *f = ret_file(fd, &all_f);
    int n = 0;
    char *lnbuf = 0;

    if (READ_SIZE < 0)
        return 0;
    while (1) {
        if (readret <= f->ridx) {
            reread(f, &n, &readret, fd);
            if (readret <= 0)
                return (readret == 0) ? lnbuf : 0;
        }
        if (f->rbuf[f->ridx + n] == ch)
            return append(lnbuf, n, f);
        if (f->ridx + n == readret - 1)
            lnbuf = append(lnbuf, n + 1, f);
        n++;
    }
}

char *getl(const int fd)
{
    return getd(fd, '\n');
}
