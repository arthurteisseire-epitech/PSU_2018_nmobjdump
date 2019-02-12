/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** sections.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
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


void print_ascci(const unsigned char *p, size_t neg_off)
{
    p -= neg_off;
    printf(" ");
    for (size_t i = 0; i < neg_off + 1; ++i) {
        if (isprint(p[i]))
            printf("%c", p[i]);
        else
            printf(".");
    }
    printf("\n");
}

void print_sides(const unsigned char *section, size_t count, size_t i)
{
    size_t nb_spaces = (((16 - count) * 2) + (16 - count) / 4);

    for (size_t j = 0; j < nb_spaces; ++j)
        printf(" ");
    print_ascci(&section[i], count - 1);
}

void print_section(Elf64_Ehdr *hdr, Elf64_Shdr *shdr)
{
    const unsigned char *section = (void *) hdr + shdr->sh_offset;
    size_t count = 0;

    printf("Contents of section %s:\n", find_string(hdr, shdr->sh_name));
    printf("%04x", 0);
    for (size_t i = 0; i < shdr->sh_size; i++) {
        if (i % 4 == 0)
            printf(" ");
        printf("%02x", section[i]);
        ++count;
        if (i == shdr->sh_size - 1) {
            print_sides(section, count, i);
        } else if ((i + 1) % 16 == 0) {
            print_sides(section, count, i);
            printf("%04x", (unsigned)i + 1);
            count = 0;
        }
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
