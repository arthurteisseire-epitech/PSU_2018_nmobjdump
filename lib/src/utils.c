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
    return (hdr + _E(hdr, e_shoff));
}

const void *sec(const void *hdr, size_t idx)
{
    return (first_shdr(hdr) + _E(hdr, e_shentsize) * idx);
}

const void *get_symbol(const void *hdr, size_t shdr_idx, size_t idx)
{
    const void *shdr = hdr + _SI(hdr, shdr_idx, sh_offset);

    return (shdr + _SI(hdr, shdr_idx, sh_entsize) * idx);
}

unsigned get_arch(const void *hdr)
{
    const char *ident = hdr;

    if (ident[EI_CLASS] == ELFCLASS32)
        return (32);
    else if (ident[EI_CLASS] == ELFCLASS64)
        return (64);
    return (0);
}
