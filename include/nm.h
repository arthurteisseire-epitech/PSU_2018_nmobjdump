/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** nm.h
*/

#ifndef PSU_2018_NMOBJDUMP_NM_H
#define PSU_2018_NMOBJDUMP_NM_H

#include <elf.h>

Elf64_Ehdr *file_to_hdr(const char *filename);

Elf64_Shdr *get_section_header(const Elf64_Ehdr *hdr);
Elf64_Shdr *get_section(const Elf64_Ehdr *hdr, int idx);

static Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, int idx);
Elf64_Sym *print_file_symbols(const Elf64_Ehdr *hdr);

#endif
