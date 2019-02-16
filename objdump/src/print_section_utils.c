/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_utils.c
*/

#include <ctype.h>
#include <stdio.h>

void print_chars(const unsigned char *p, size_t neg_off)
{
    p -= neg_off;
    printf(" ");
    for (size_t i = 0; i < neg_off + 1; ++i) {
        if (isprint(p[i]))
            printf("%c", p[i]);
        else
            printf(".");
    }
}

size_t bytes_on_raw(unsigned i)
{
    ++i;
    if (i % 16 == 0)
        return (16);
    return (i % 16);
}

void print_ascii(const unsigned char *section, unsigned i)
{
    const size_t bor = bytes_on_raw(i);
    const size_t missing_bytes_on_raw = 16 - bor;
    size_t nb_spaces = missing_bytes_on_raw * 2 + missing_bytes_on_raw / 4;

    for (size_t j = 0; j < nb_spaces + 1; ++j)
        printf(" ");
    print_chars(&section[i], bor - 1);
    for (size_t j = 0; j < missing_bytes_on_raw; ++j)
        printf(" ");
    printf("\n");
}
