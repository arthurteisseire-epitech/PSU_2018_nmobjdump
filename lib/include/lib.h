/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** lib.h
*/

#ifndef PSU_2018_NMOBJDUMP_LIB_H
#define PSU_2018_NMOBJDUMP_LIB_H

#include <elf.h>
#include <stddef.h>

typedef union ehdr_s {
    Elf64_Ehdr *member_64;
    Elf32_Ehdr *member_32;
} ehdr_t;

typedef union shdr_s {
    Elf64_Shdr *member_64;
    Elf32_Shdr *member_32;
} shdr_t;

typedef union sym_s {
    Elf64_Sym *member_64;
    Elf32_Sym *member_32;
} sym_t;

#define _M(hdr, m_name) (get_arch(hdr) == 64 ?\
    hdr->member_64->m_name : hdr->member_32->m_name)

int check_supported(Elf64_Ehdr *hdr, const char *filename);
Elf64_Ehdr *file_to_hdr(const char *prog, const char *filename);

int error(const char *message, ...);

Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, size_t idx);
Elf64_Shdr *sec(const Elf64_Ehdr *hdr, size_t idx);
Elf64_Shdr *first_shdr(const Elf64_Ehdr *hdr);
unsigned get_arch(const void *hdr);

int exec(int ac, const char **av, const char *prog_name,
void (*ex)(const void *, const char *, int));

int exec_main(int ac, const char **av, const char *prog_name,
void (*ex)(const void *, const char *, int));

void *find_string_table(const Elf64_Ehdr *hdr);
char *find_string(const Elf64_Ehdr *hdr, int offset);

#endif
