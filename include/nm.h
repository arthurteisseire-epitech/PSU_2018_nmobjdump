/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** nm.h
*/

#ifndef PSU_2018_NMOBJDUMP_NM_H
#define PSU_2018_NMOBJDUMP_NM_H

#include <elf.h>

Elf64_Shdr *elf_sheader(const Elf64_Ehdr *hdr);
Elf64_Shdr *elf_section(const Elf64_Ehdr *hdr, int idx);

static Elf64_Sym *elf_sym(const Elf64_Ehdr *hdr, int idx);
Elf64_Sym *elf_find_sym(Elf64_Ehdr *elf);

#endif
