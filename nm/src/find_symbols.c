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
#include "nm.h"

static int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && tolower(s1[i]) == tolower(s2[i]))
        ++i;
    if (i > 0 && tolower(s1[i - 1]) == tolower(s2[i - 1])) {
        if (!isalpha(s1[i]))
            return (1);
        else if (!isalpha(s2[i]))
            return (-1);
    }
    return (tolower(s1[i]) - tolower(s2[i]));
}

int cmp(const symbol_t *a, const symbol_t *b)
{
    int it_a;
    int it_b;
    int res;

    for (it_a = 0; !isalpha(a->name[it_a]); ++it_a);
    for (it_b = 0; !isalpha(b->name[it_b]); ++it_b);
    res = my_strcmp(&a->name[it_a], &b->name[it_b]);
    if (res == 0)
        return (it_a < it_b);
    return (res);
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
    qsort(nm->symbols, nm->len, sizeof(symbol_t),
          (int (*)(const void *, const void *)) cmp);
    print_symbols(nm);
    free(nm->symbols);
    free(nm);
}