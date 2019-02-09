/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_symbol.c
*/

#include <stdio.h>
#include "nm.h"

void print_symbol(const Elf64_Ehdr *hdr, const Elf64_Shdr *current_section, int j)
{
    Elf64_Shdr *strtab = get_section(hdr, current_section->sh_link);
    Elf64_Sym *sym = get_symbol((void *) hdr + current_section->sh_offset, j);
    char *name = (char *) hdr + strtab->sh_offset + sym->st_name;

    if ((ELF64_ST_BIND(sym->st_info) & STT_OBJECT) || ELF64_ST_BIND(sym->st_info) & STT_FUNC)
        printf("symbol name : %s\n", name);
}
