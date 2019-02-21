/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_symbol.c
*/

#include <stdio.h>
#include "lib.h"
#include "nm.h"

static void print_sym(const nm_t *nm, const void *hdr, size_t i)
{
    int n = get_arch(hdr) == 64 ? 16 : 8;

    if (nm->symbols[i].type == 'U' || nm->symbols[i].type == 'w')
        printf("%*c %s\n", n + 2, nm->symbols[i].type, nm->symbols[i].name);
    else
        printf("%0*x %c %s\n", n, nm->symbols[i].value,
        nm->symbols[i].type, nm->symbols[i].name);
}

void print_symbols(nm_t *nm, const void *hdr)
{
    for (size_t i = 0; i < nm->len; ++i)
        print_sym(nm, hdr, i);
}

