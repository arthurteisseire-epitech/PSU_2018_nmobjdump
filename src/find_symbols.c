/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** symbol.c
*/

#include <stdio.h>
#include "nm.h"

static void print_section_symbols(const Elf64_Ehdr *hdr, const Elf64_Shdr *current_section)
{
    for (int j = 0; j < current_section->sh_size / current_section->sh_entsize; ++j)
        print_symbol(hdr, current_section, j);
}

Elf64_Sym *print_file_symbols(const Elf64_Ehdr *hdr)
{
    Elf64_Shdr *current_section = get_section_header(hdr);

    for (int i = 0; i < hdr->e_shnum; ++i) {
        if (current_section->sh_type == SHT_SYMTAB || current_section->sh_type == SHT_DYNSYM)
            print_section_symbols(hdr, current_section);
        current_section = (void *) current_section + hdr->e_shentsize;
    }
    return (NULL);
}
