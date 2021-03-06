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

void print_ascii_on_eol(const unsigned char *section, const size_t tot_bytes,
unsigned i)
{
    if (bytes_on_raw(i) == 16 || i == tot_bytes - 1)
        print_ascii(section, i);
}

void print_byte(const unsigned char *section, size_t i)
{
    if (i % 4 == 0)
        printf(" ");
    printf("%02x", section[i]);
}

int get_index(int n)
{
    int nb_bytes = 0;

    while (n != 0) {
        n >>= 4;
        nb_bytes++;
    }
    return (nb_bytes < 4 ? 4 : nb_bytes);
}

void print_index_on_new_line(const void *hdr, size_t idx, unsigned int i)
{
    int size = _SI(hdr, idx, sh_addr) + _SI(hdr, idx, sh_size);

    if (bytes_on_raw(i) == 1)
        printf(" %0*x", get_index(size), i + (unsigned) _SI(hdr, idx, sh_addr));
}

void print_section(const void *hdr, size_t idx)
{
    const unsigned char *section = hdr + _SI(hdr, idx, sh_offset);
    const char *section_name = find_string(hdr, _SI(hdr, idx, sh_name));
    const size_t tot_bytes = _SI(hdr, idx, sh_size);

    printf("Contents of section %s:\n", section_name);
    for (unsigned i = 0; i < tot_bytes; ++i) {
        print_index_on_new_line(hdr, idx, i);
        print_byte(section, i);
        print_ascii_on_eol(section, tot_bytes, i);
    }
}
