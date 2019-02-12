/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** objdump.h
*/

#ifndef PSU_2018_NMOBJDUMP_OBJDUMP_H
#define PSU_2018_NMOBJDUMP_OBJDUMP_H

#include <elf.h>

typedef struct map_s {
    uint16_t byte;
    const char *name;
} map_t;

Elf64_Shdr *find_string_table(Elf64_Ehdr *hdr);
char *find_string(Elf64_Ehdr *hdr, int offset);

void print_header(const Elf64_Ehdr *hdr, const char *filename);

void print_sections(Elf64_Ehdr *hdr);
void print_section(Elf64_Ehdr *hdr, Elf64_Shdr *shdr);

#endif
