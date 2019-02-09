/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** symbol.c
*/

#include <stdio.h>
#include "nm.h"

Elf64_Sym *elf_sym(Elf64_Shdr *hdr, int idx)
{
    return (Elf64_Sym *) &hdr[idx];
}

Elf64_Sym *elf_find_sym(Elf64_Ehdr *elf)
{
    Elf64_Shdr *current_section = elf_sheader(elf);

    for (int i = 0; i < elf->e_shnum; ++i) {
        if (current_section->sh_type == SHT_SYMTAB || current_section->sh_type == SHT_DYNSYM) {
            printf("%lu\n", current_section->sh_size);
            printf("%lu\n", sizeof(Elf64_Sym));
            printf("%lu\n", current_section->sh_entsize);
            printSymbols(elf_find_string(elf, elf_sym(current_section, 0)->st_name));
            return ((Elf64_Sym *) current_section);
        }
        current_section = (void *) current_section + elf->e_shentsize;
    }
    return (NULL);
}

void printSymbols(char *section_string_table)
{
    if (section_string_table == NULL)
        printf("NULL\n");
    else
        printf("%s\n", section_string_table);
    printf("symbol table\n");
}
