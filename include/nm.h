/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** nm.h
*/

#ifndef PSU_2018_NMOBJDUMP_NM_H
#define PSU_2018_NMOBJDUMP_NM_H

#include <elf.h>

Elf64_Shdr *elf_sheader(Elf64_Ehdr *hdr);
Elf64_Shdr *elf_section(Elf64_Ehdr *hdr, int idx);

#endif
