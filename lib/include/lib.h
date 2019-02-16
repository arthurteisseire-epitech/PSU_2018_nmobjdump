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

int check_supported(Elf64_Ehdr *hdr, const char *filename);
Elf64_Ehdr *file_to_hdr(const char *prog, const char *filename);

int error(const char *message, ...);

Elf64_Sym *get_symbol(const Elf64_Ehdr *hdr, size_t idx);
Elf64_Shdr *sec(const Elf64_Ehdr *hdr, size_t idx);
Elf64_Shdr *first_shdr(const Elf64_Ehdr *hdr);

int exec(int ac, const char **av, const char *prog_name,
void (*ex)(const void *, const char *, int));

#endif
