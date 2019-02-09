/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** add_symbol.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "nm.h"

void add_symbol(nm_t *nm, const Elf64_Ehdr *hdr, const Elf64_Shdr *current_section, int i)
{
    Elf64_Shdr *strtab = get_section(hdr, current_section->sh_link);
    Elf64_Sym *sym = get_symbol((void *) hdr + current_section->sh_offset, i);
    char *name = (char *) hdr + strtab->sh_offset + sym->st_name;

    if ((ELF64_ST_BIND(sym->st_info) & STT_OBJECT) || ELF64_ST_BIND(sym->st_info) & STT_FUNC) {
        nm->len++;
        nm->symbols = realloc(nm->symbols, nm->len * sizeof(symbol_t));
        nm->symbols[nm->len - 1].name = name;
    }
}
