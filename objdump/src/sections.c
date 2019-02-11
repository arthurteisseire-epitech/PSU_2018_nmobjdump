/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** sections.c
*/

#include <stdio.h>
#include <stdbool.h>
#include "objdump.h"
#include "lib.h"

static bool is_section_printable(const Elf64_Shdr *current_section)
{
    return (current_section->sh_type != SHT_NOBITS &&
            current_section->sh_type != SHT_NULL &&
            current_section->sh_type != SHT_RELA &&
            current_section->sh_type != SHT_SYMTAB &&
            current_section->sh_type != SHT_STRTAB &&
            current_section->sh_size != 0);
}

static void print_column(const unsigned char *section, size_t idx)
{
    printf("%02x", section[idx]);
}

void print_section(Elf64_Ehdr *hdr, Elf64_Shdr *shdr)
{
    const unsigned char *section = (void *) hdr + shdr->sh_offset;

    printf("\n%s\n", find_string(hdr, shdr->sh_name));
    for (size_t i = 0; i < shdr->sh_size; i++) {
        print_column(section, i);
        if ((i + 1) % 4 == 0)
            printf(" ");
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
}

void print_sections(Elf64_Ehdr *hdr)
{
    Elf64_Shdr *current_section = get_section_header(hdr);

    for (size_t i = 0; i < hdr->e_shnum; ++i) {
        if (is_section_printable(current_section))
            print_section(hdr, current_section);
        current_section = (void *) current_section + hdr->e_shentsize;
    }
}
