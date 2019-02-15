/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** objdump.h
*/

#ifndef PSU_2018_NMOBJDUMP_OBJDUMP_H
#define PSU_2018_NMOBJDUMP_OBJDUMP_H

#include <elf.h>

#define NO_FLAGS    0x00
#define HAS_RELOC    0x01
#define EXEC_P        0x02
#define HAS_DEBUG    0x08
#define HAS_SYMS    0x10
#define HAS_LOCALS    0x20
#define DYNAMIC    0x40
#define D_PAGED    0x100

typedef struct map_s {
    uint16_t byte;
    const char *name;
} map_t;

typedef struct flags_s {
    uint32_t type;
    uint32_t flag;
} flags_t;

Elf64_Shdr *find_string_table(const Elf64_Ehdr *hdr);

char *find_string(const Elf64_Ehdr *hdr, int offset);
void print_header(const Elf64_Ehdr *hdr, const char *filename);
void print_sections(const Elf64_Ehdr *hdr);
void print_section(const Elf64_Ehdr *hdr, size_t i);

#endif
