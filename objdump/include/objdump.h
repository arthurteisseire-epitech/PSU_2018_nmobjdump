/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** objdump.h
*/

#ifndef PSU_2018_NMOBJDUMP_OBJDUMP_H
#define PSU_2018_NMOBJDUMP_OBJDUMP_H

#include <elf.h>

Elf64_Shdr *find_string_table(Elf64_Ehdr *hdr);
char *find_string(Elf64_Ehdr *hdr, int offset);

void print_sections(Elf64_Ehdr *hdr);
void print_section(Elf64_Ehdr *hdr, Elf64_Shdr *shdr);

#endif
