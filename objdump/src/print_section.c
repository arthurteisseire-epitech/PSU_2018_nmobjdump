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

void print_chars(const unsigned char *p, size_t neg_off)
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

static size_t bytes_on_raw(unsigned i)
{
    ++i;
    if (i % 16 == 0)
        return (16);
    return (i % 16);
}

void print_ascii(const unsigned char *section, unsigned i)
{
    const size_t bor = bytes_on_raw(i);
    const size_t missing_bytes_on_raw = 16 - bor;
    size_t nb_spaces = missing_bytes_on_raw * 2 + missing_bytes_on_raw / 4;

    for (size_t j = 0; j < nb_spaces + 1; ++j)
        printf(" ");
    print_chars(&section[i], bor - 1);
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
    for (unsigned i = 0; i < tot_bytes; ++i) {
        if (bytes_on_raw(i) == 1)
            printf(" %04x", i + (unsigned) get_section(hdr, idx)->sh_addr);
        print_byte(section, i);
        if (bytes_on_raw(i) == 16 || i == tot_bytes - 1)
            print_ascii(section, i);
    }
}
