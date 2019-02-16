/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_header.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

void print_header(const Elf64_Ehdr *hdr, const char *filename)
{
    unsigned flags = get_flags(hdr, hdr->e_type, hdr->e_shnum);

    printf("\n%s:     file format elf64-x86-64\n", filename);
    printf("architecture: %s, ", get_machine_name(hdr->e_machine));
    printf("flags 0x%08x:\n", flags);
    print_flags(flags, 0, "");
    printf("\nstart address 0x%016lx\n\n", hdr->e_entry);
}

