/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** objdump.h
*/

#ifndef PSU_2018_NMOBJDUMP_OBJDUMP_H
#define PSU_2018_NMOBJDUMP_OBJDUMP_H

#include <elf.h>
#include "lib.h"

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

void print_sections(const void *hdr, size_t shnum);
void print_section(const void *hdr, size_t i);

void print_ascii(const unsigned char *section, unsigned i);
size_t bytes_on_raw(unsigned i);
void print_chars(const unsigned char *p, size_t neg_off);

void print_flags(unsigned int flags, unsigned int i, char *comma);
const char *get_machine_name(Elf64_Half machine);
unsigned int sym_flags(const void *hdr, size_t shnum);
unsigned int get_flags(const void *hdr, uint16_t elf_type, size_t shnum);

void print_architecture(Elf64_Half machine);
void print_all_flags(const void *hdr, uint16_t type, size_t shnum);
void print_address(size_t entry);

#endif
