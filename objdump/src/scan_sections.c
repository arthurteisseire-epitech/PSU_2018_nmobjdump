/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** sections.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "objdump.h"
#include "lib.h"

static bool is_section_printable(const Elf64_Ehdr *hdr, size_t idx)
{
    const Elf64_Shdr *shdr = get_section(hdr, idx);

    return (shdr->sh_type != SHT_NOBITS &&
    shdr->sh_type != SHT_NULL &&
    strcmp(find_string(hdr, shdr->sh_name), ".strtab") != 0 &&
    strcmp(find_string(hdr, shdr->sh_name), ".symtab") != 0 &&
    strcmp(find_string(hdr, shdr->sh_name), ".shstrtab") != 0 &&
    strcmp(find_string(hdr, shdr->sh_name), ".bss") != 0 &&
    shdr->sh_size != 0);
}

void print_sections(const Elf64_Ehdr *hdr)
{
    for (size_t i = 0; i < hdr->e_shnum; ++i)
        if (is_section_printable(hdr, i))
            print_section(hdr, i);
}
