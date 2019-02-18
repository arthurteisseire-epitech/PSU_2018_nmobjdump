/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** section.c
*/

#include <stddef.h>
#include <elf.h>
#include <string.h>

Elf64_Shdr *first_shdr(const Elf64_Ehdr *hdr)
{
    return ((Elf64_Shdr *) ((void *) hdr + hdr->e_shoff));
}

Elf64_Shdr *sec(const Elf64_Ehdr *hdr, size_t idx)
{
    return (&first_shdr(hdr)[idx]);
}

Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, size_t idx)
{
    return (&((Elf64_Sym *) hdr)[idx]);
}

unsigned get_arch(const void *hdr)
{
    char ident[EI_NIDENT];

    memcpy(ident, hdr, EI_NIDENT);
    if (ident[EI_CLASS] == ELFCLASS32)
        return (32);
    else if (ident[EI_CLASS] == ELFCLASS64)
        return (64);
    return (0);
}
