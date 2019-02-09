/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** nm.h
*/

#ifndef PSU_2018_NMOBJDUMP_NM_H
#define PSU_2018_NMOBJDUMP_NM_H

#include <stddef.h>
#include <elf.h>

typedef struct symbol_s {
    Elf64_Addr value;
    char type;
    char *name;
} symbol_t;

typedef struct nm_s {
    symbol_t *symbols;
    size_t len;
} nm_t;

Elf64_Ehdr *file_to_hdr(const char *filename);

Elf64_Shdr *get_section_header(const Elf64_Ehdr *hdr);
Elf64_Shdr *get_section(const Elf64_Ehdr *hdr, int idx);
Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, int idx);

void print_file_symbols(const Elf64_Ehdr *hdr);

void add_symbol(nm_t *nm, const Elf64_Ehdr *hdr, const Elf64_Shdr *current_section, int i);

#endif
