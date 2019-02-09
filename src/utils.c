/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** section.c
*/

#include <elf.h>

Elf64_Shdr *get_section_header(const Elf64_Ehdr *hdr)
{
    return ((Elf64_Shdr *) ((void *) hdr + hdr->e_shoff));
}

Elf64_Shdr *get_section(const Elf64_Ehdr *hdr, int idx)
{
    return (&get_section_header(hdr)[idx]);
}

Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, int idx)
{
    return (&((Elf64_Sym *) hdr)[idx]);
}
