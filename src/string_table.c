/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** string_table.c
*/

#include <stdlib.h>
#include "nm.h"

char *elf_str_table(Elf64_Ehdr *hdr)
{
    if (hdr->e_shstrndx == SHN_UNDEF)
        return (NULL);
    return ((void *) hdr + elf_section(hdr, hdr->e_shstrndx)->sh_offset);
}

char *elf_find_string(Elf64_Ehdr *hdr, size_t offset)
{
    char *strtab = elf_str_table(hdr);

    if (strtab == NULL)
        return (NULL);
    return (strtab + offset);
}

