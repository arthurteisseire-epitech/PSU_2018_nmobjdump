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

static bool is_section_printable(const Elf64_Ehdr *hdr, const Elf64_Shdr *shdr)
{
    return (shdr->sh_type != SHT_NOBITS &&
            shdr->sh_type != SHT_NULL &&
            strcmp(find_string(hdr, shdr->sh_name), ".strtab") != 0 &&
            strcmp(find_string(hdr, shdr->sh_name), ".symtab") != 0 &&
            strcmp(find_string(hdr, shdr->sh_name), ".shstrtab") != 0 &&
            strcmp(find_string(hdr, shdr->sh_name), ".bss") != 0 &&
            shdr->sh_size != 0);
}

void print_sections(Elf64_Ehdr *hdr)
{
    for (size_t i = 0; i < hdr->e_shnum; ++i)
        if (is_section_printable(hdr, get_section(hdr, i)))
            print_section(hdr, get_section(hdr, i));
}
