/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** find_string.c
*/

#include <elf.h>
#include <stddef.h>
#include "lib.h"

void *find_string_table(const Elf64_Ehdr *hdr)
{
    if (hdr->e_shstrndx == SHN_UNDEF)
        return (NULL);
    return ((void *) hdr + get_section(hdr, hdr->e_shstrndx)->sh_offset);
}

char *find_string(const Elf64_Ehdr *hdr, int offset)
{
    void *string_table = find_string_table(hdr);

    if (string_table == NULL)
        return (NULL);
    return (string_table + offset);
}

