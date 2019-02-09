/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** symbol.c
*/

#include <stdio.h>
#include "nm.h"

void printSymbolsSection(const Elf64_Ehdr *elf, const Elf64_Shdr *current_section);

static Elf64_Sym *elf_sym(const Elf64_Ehdr *hdr, int idx)
{
    return (&((Elf64_Sym *) hdr)[idx]);
}

Elf64_Sym *elf_find_sym(Elf64_Ehdr *elf)
{
    Elf64_Shdr *current_section = elf_sheader(elf);

    for (int i = 0; i < elf->e_shnum; ++i) {
        if (current_section->sh_type == SHT_SYMTAB || current_section->sh_type == SHT_DYNSYM)
            printSymbolsSection(elf, current_section);
        current_section = (void *) current_section + elf->e_shentsize;
    }
    return (NULL);
}

void printSymbolsSection(const Elf64_Ehdr *elf, const Elf64_Shdr *current_section)
{
    Elf64_Shdr *strtab = elf_section(elf, current_section->sh_link);

    for (int j = 0; j < current_section->sh_size / current_section->sh_entsize; ++j) {
        Elf64_Sym *sym = elf_sym((void *) elf + current_section->sh_offset, j);
        if (ELF64_ST_BIND(sym->st_info) & STT_OBJECT) {
            const char *name = (const char *) elf + strtab->sh_offset + sym->st_name;
            printf("symbol name : %s\n", name);
        }
    }
}

void printSymbols(char *section_string_table)
{
    if (section_string_table == NULL)
        printf("NULL\n");
    else
        printf("%s\n", section_string_table);
}
