/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** find_symbol.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "nm.h"
#include "lib.h"

static void add_section_symbols(nm_t *nm, const void *hdr, size_t idx)
{
    size_t nb_symbols = 0;

    if (_SI(hdr, idx, sh_entsize) != 0)
        nb_symbols = _SI(hdr, idx, sh_size) / _SI(hdr, idx, sh_entsize);
    for (size_t i = 0; i < nb_symbols; ++i)
        add_symbol(nm, hdr, idx, i);
}

bool print_file_symbols(const void *hdr, size_t shnum)
{
    nm_t *nm = calloc(1, sizeof(nm_t));
    bool is_symbols;

    for (size_t i = 0; i < shnum; ++i)
        if (_SI(hdr, i, sh_type) == SHT_SYMTAB)
            add_section_symbols(nm, hdr, i);
    print_symbols(nm, hdr);
    free(nm->symbols);
    is_symbols = nm->len != 0;
    free(nm);
    return (is_symbols);
}
