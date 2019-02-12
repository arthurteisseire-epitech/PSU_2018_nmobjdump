/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** section.c
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "objdump.h"
#include "lib.h"

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
}

void print_sides(const unsigned char *section, size_t count, size_t i)
{
    size_t nb_spaces = (((16 - count) * 2) + (16 - count) / 4);

    for (size_t j = 0; j < nb_spaces + 1; ++j)
        printf(" ");
    print_ascci(&section[i], count - 1);
    for (size_t j = 0; j < 16 - (count - 1); ++j)
        printf(" ");
    printf("\n");
}

void print_section(Elf64_Ehdr *hdr, Elf64_Shdr *shdr)
{
    unsigned off = (unsigned)shdr->sh_addr;
    const unsigned char *section = (void *) hdr + shdr->sh_offset;
    size_t count = 0;

    printf("Contents of section %s:\n", find_string(hdr, shdr->sh_name));
    printf(" %04x", off);
    for (size_t i = 0; i < shdr->sh_size; i++) {
        if (i % 4 == 0)
            printf(" ");
        printf("%02x", section[i]);
        ++count;
        if (i == shdr->sh_size - 1) {
            print_sides(section, count, i);
        } else if ((i + 1) % 16 == 0) {
            print_sides(section, count, i);
            printf(" %04x", off + 1);
            count = 0;
        }
        ++off;
    }
}
