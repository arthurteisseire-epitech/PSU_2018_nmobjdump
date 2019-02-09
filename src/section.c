/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** section.c
*/

#include <elf.h>

Elf64_Shdr *elf_sheader(const Elf64_Ehdr *hdr)
{
    return ((Elf64_Shdr *) ((void *) hdr + hdr->e_shoff));
}

Elf64_Shdr *elf_section(const Elf64_Ehdr *hdr, int idx)
{
    return (&elf_sheader(hdr)[idx]);
}
