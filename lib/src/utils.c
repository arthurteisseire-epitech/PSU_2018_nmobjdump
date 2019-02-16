/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** section.c
*/

#include <stddef.h>
#include <elf.h>

Elf64_Shdr *get_section_header(const Elf64_Ehdr *hdr)
{
    return ((Elf64_Shdr *) ((void *) hdr + hdr->e_shoff));
}

Elf64_Shdr *sec(const Elf64_Ehdr *hdr, size_t idx)
{
    return (&get_section_header(hdr)[idx]);
}

Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, size_t idx)
{
    return (&((Elf64_Sym *) hdr)[idx]);
}
