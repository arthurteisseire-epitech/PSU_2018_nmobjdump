/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** sections.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

void print_section(Elf64_Ehdr *hdr, Elf64_Shdr *shdr)
{
    printf("%s\n", find_string(hdr, shdr->sh_name));
}

void print_sections(Elf64_Ehdr *hdr)
{
    Elf64_Shdr *current_section = get_section_header(hdr);

    for (size_t i = 0; i < hdr->e_shnum; ++i) {
        if (current_section->sh_type != SHT_NOBITS &&
            current_section->sh_type != SHT_NULL &&
            current_section->sh_type != SHT_RELA &&
            current_section->sh_type != SHT_SYMTAB &&
            current_section->sh_type != SHT_STRTAB &&
            current_section->sh_size != 0)
            print_section(hdr, current_section);
        current_section = (void *) current_section + hdr->e_shentsize;
    }
}
