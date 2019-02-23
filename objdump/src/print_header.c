/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_header.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

static void print_architecture(Elf64_Half machine)
{
    printf("file format %s\n", get_format(machine));
    printf("architecture: %s, ", get_machine_name(machine));
}

static void print_all_flags(const void *hdr, uint16_t type, size_t shnum)
{
    unsigned flags = get_flags(hdr, type, shnum);

    printf("flags 0x%08x:\n", flags);
    print_flags(flags, 0, "");
}

static void print_address(const void *hdr, size_t entry)
{
    int n = get_arch(hdr) == 64 ? 16 : 8;

    printf("\nstart address 0x%0*lx\n\n", n, entry);
}

void print_header(const void *hdr, const char *filename)
{
    printf("\n%s:     ", filename);
    print_architecture(_E(hdr, e_machine));
    print_all_flags(hdr, _E(hdr, e_type), _E(hdr, e_shnum));
    print_address(hdr, _E(hdr, e_entry));
}
