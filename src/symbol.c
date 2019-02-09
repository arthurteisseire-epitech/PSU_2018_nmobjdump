/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** symbol.c
*/

#include <stdio.h>
#include "nm.h"

static Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, int idx)
{
    return (&((Elf64_Sym *) hdr)[idx]);
}

void print_symbol(const Elf64_Ehdr *hdr, const Elf64_Shdr *current_section, int j)
{
    Elf64_Shdr *strtab = get_section(hdr, current_section->sh_link);
    Elf64_Sym *sym = get_symbol((void *) hdr + current_section->sh_offset, j);
    char *name = (char *) hdr + strtab->sh_offset + sym->st_name;;

    if ((ELF64_ST_BIND(sym->st_info) & STT_OBJECT) || ELF64_ST_BIND(sym->st_info) & STT_FUNC)
        printf("symbol name : %s\n", name);
}

static void print_symbol_section(const Elf64_Ehdr *hdr, const Elf64_Shdr *current_section)
{
    for (int j = 0; j < current_section->sh_size / current_section->sh_entsize; ++j)
        print_symbol(hdr, current_section, j);
}

Elf64_Sym *print_symbols(const Elf64_Ehdr *hdr)
{
    Elf64_Shdr *current_section = get_section_header(hdr);

    for (int i = 0; i < hdr->e_shnum; ++i) {
        if (current_section->sh_type == SHT_SYMTAB || current_section->sh_type == SHT_DYNSYM)
            print_symbol_section(hdr, current_section);
        current_section = (void *) current_section + hdr->e_shentsize;
    }
    return (NULL);
}
