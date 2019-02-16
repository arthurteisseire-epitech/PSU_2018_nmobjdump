/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_header.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

void print_architecture(Elf64_Half machine)
{
    printf("architecture: %s, ", get_machine_name(machine));
}

void print_all_flags(const void *hdr, uint16_t type, size_t shnum)
{
    unsigned flags = get_flags(hdr, type, shnum);

    printf("flags 0x%08x:\n", flags);
    print_flags(flags, 0, "");
}

void print_address(size_t entry)
{
    printf("\nstart address 0x%016lx\n\n", entry);
}

void print_header(const Elf64_Ehdr *hdr)
{
    print_architecture(hdr->e_machine);
    print_all_flags(hdr, hdr->e_type, hdr->e_shnum);
    print_address(hdr->e_entry);
}

