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
        print_section(hdr, current_section);
        current_section = (void *) current_section + hdr->e_shentsize;
    }
}

