/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** nm.h
*/

#ifndef PSU_2018_NMOBJDUMP_NM_H
#define PSU_2018_NMOBJDUMP_NM_H

#include <stddef.h>
#include <stdbool.h>
#include <elf.h>

typedef struct symbol_s {
    unsigned value;
    char type;
    char *name;
} symbol_t;

typedef struct nm_s {
    symbol_t *symbols;
    size_t len;
} nm_t;

typedef struct map_s {
    char c;
    unsigned type;
    unsigned flag;
} map_t;

bool print_file_symbols(const void *hdr, size_t shnum);
void add_symbol(nm_t *nm, const void *hdr, size_t idx,
    size_t i);
void print_symbols(nm_t *nm, const void *hdr);

#endif
