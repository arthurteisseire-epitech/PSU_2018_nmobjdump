/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** section.c
*/

#include <stddef.h>
#include <elf.h>
#include <string.h>
#include "lib.h"

const void *first_shdr(const void *hdr)
{
    return (hdr + _M(hdr, e_shoff));
}

const void *sec(const void *hdr, size_t idx)
{
    return (first_shdr(hdr) + _M(hdr, e_shentsize) * idx);
}

Elf64_Sym *get_symbol(const void *hdr, size_t idx)
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
