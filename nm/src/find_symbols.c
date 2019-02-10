/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** find_symbol.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nm.h"

int cmp(const void *a, const void *b)
{
    const symbol_t *symbol_a = a;
    const symbol_t *symbol_b = b;

    return (strcmp(symbol_a->name, symbol_b->name));
}

static void print_symbols(nm_t *nm)
{
    for (size_t i = 0; i < nm->len; ++i) {
        if (nm->symbols[i].value)
            printf("%016x %c %s\n", (unsigned) nm->symbols[i].value,
                   nm->symbols[i].type, nm->symbols[i].name);
        else
            printf("%18c %s\n", nm->symbols[i].type, nm->symbols[i].name);
    }
}

static void add_section_symbols(nm_t *nm, const Elf64_Ehdr *hdr,
                                const Elf64_Shdr *current_section)
{
    size_t nb_symbols = 0;

    if (current_section->sh_entsize != 0)
        nb_symbols = current_section->sh_size / current_section->sh_entsize;
    for (size_t i = 0; i < nb_symbols; ++i)
        add_symbol(nm, hdr, current_section, i);
}

void print_file_symbols(const Elf64_Ehdr *hdr)
{
    Elf64_Shdr *current_section = get_section_header(hdr);
    nm_t *nm = calloc(1, sizeof(nm_t));

    for (size_t i = 0; i < hdr->e_shnum; ++i) {
        if (current_section->sh_type == SHT_SYMTAB)
            add_section_symbols(nm, hdr, current_section);
        current_section = (void *) current_section + hdr->e_shentsize;
    }
    qsort(nm->symbols, nm->len, sizeof(symbol_t), cmp);
    print_symbols(nm);
    free(nm->symbols);
    free(nm);
}
