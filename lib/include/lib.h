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
    const void *u;
    const Elf64_Ehdr *member_64;
    const Elf32_Ehdr *member_32;
} ehdr_t;

typedef union shdr_s {
    const void *u;
    const Elf64_Shdr *member_64;
    const Elf32_Shdr *member_32;
} shdr_t;

typedef union sym_s {
    const void *u;
    const Elf64_Sym *member_64;
    const Elf32_Sym *member_32;
} sym_t;

#define _E(hdr, m_name) (get_arch(hdr) == 64 ?\
    ((ehdr_t)hdr).member_64->m_name : ((ehdr_t)hdr).member_32->m_name)

#define _SI(hdr, idx, m_name) (get_arch(hdr) == 64 ?\
    ((shdr_t)sec(hdr, idx)).member_64->m_name :\
    ((shdr_t)sec(hdr, idx)).member_32->m_name)

#define _SYM(hdr, sym, m_name) (get_arch(hdr) == 64 ?\
    ((sym_t)sym).member_64->m_name : ((sym_t)sym).member_32->m_name)

int check_supported(const void *hdr, const char *filename, const char *prog);
void *file_to_hdr(const char *prog, const char *filename);

int error(const char *message, ...);

const void *get_symbol(const void *hdr, size_t shdr_idx, size_t idx);
const void *sec(const void *hdr, size_t idx);
const void *first_shdr(const void *hdr);
unsigned get_arch(const void *hdr);

int exec(int ac, const char **av, const char *prog_name,
void (*ex)(const void *, const char *, int));

int exec_main(int ac, const char **av, const char *prog_name,
void (*ex)(const void *, const char *, int));

void *find_string_table(const void *hdr);
char *find_string(const void *hdr, int offset);

#endif
