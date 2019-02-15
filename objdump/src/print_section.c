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

static size_t calc_bytes_on_raw(size_t tot_bytes, unsigned i)
{
    return (tot_bytes - (i / 16) * 16);
}

void print_sides(const unsigned char *section, size_t bytes_on_raw, size_t i)
{
    const size_t missing_bytes_on_raw = 16 - bytes_on_raw;
    size_t nb_spaces = missing_bytes_on_raw * 2 + missing_bytes_on_raw / 4;

    for (size_t j = 0; j < nb_spaces + 1; ++j)
        printf(" ");
    print_ascci(&section[i], bytes_on_raw - 1);
    for (size_t j = 0; j < missing_bytes_on_raw; ++j)
        printf(" ");
    printf("\n");
}

void print_byte(const unsigned char *section, size_t i)
{
    if (i % 4 == 0)
        printf(" ");
    printf("%02x", section[i]);
}

void print_section(const void *hdr, size_t idx)
{
    const unsigned char *section = hdr + get_section(hdr, idx)->sh_offset;
    const char *section_name = find_string(hdr, get_section(hdr, idx)->sh_name);
    const size_t tot_bytes = get_section(hdr, idx)->sh_size;

    printf("Contents of section %s:\n", section_name);
    printf(" %04x", (unsigned) get_section(hdr, idx)->sh_addr);
    for (unsigned i = 0; i < tot_bytes; ++i) {
        print_byte(section, i);
        if (i == tot_bytes - 1) {
            print_sides(section, calc_bytes_on_raw(tot_bytes, i), i);
        } else if ((i + 1) % 16 == 0) {
            print_sides(section, 16, i);
            printf(" %04x", i + (unsigned) get_section(hdr, idx)->sh_addr + 1);
        }
    }
}
