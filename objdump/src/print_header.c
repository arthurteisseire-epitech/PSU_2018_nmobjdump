/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_header.c
*/

#include <stdio.h>
#include "objdump.h"

static const map_t map[] = {
        {EM_X86_64,      "i386:x86-64"},
        {EM_NONE,        "None"},
        {EM_M32,         "WE32100"},
        {EM_SPARC,       "Sparc"},
        {EM_386,         "Intel 80386"},
        {EM_68K,         "MC68000"},
        {EM_88K,         "MC88000"},
        {EM_860,         "Intel 80860"},
        {EM_MIPS,        "MIPS R3000"},
        {EM_PARISC,      "HPPA"},
        {EM_SPARC32PLUS, "Sparc v8+"},
        {EM_PPC,         "PowerPC"},
        {EM_PPC64,       "PowerPC64"},
        {EM_S390,        "IBM S/390"},
        {EM_ARM,         "ARM"},
        {EM_SH,          "Renesas / SuperH SH"},
        {EM_SPARCV9,     "Sparc v9"},
        {EM_IA_64,       "Intel IA-64"},
        {0, NULL}
};

static const char *get_machine_name(Elf64_Half machine)
{
    for (int i = 0; map[i].name; ++i)
        if (machine == map[i].byte)
            return (map[i].name);
    return map[0].name;
}

void print_header(const Elf64_Ehdr *hdr, const char *filename)
{
    printf("\n%s:     file format elf64-x86-64\n", filename);
    printf("architecture: %s, ", get_machine_name(hdr->e_machine));
    printf("flags 0x%08x:\n", hdr->e_flags);
    printf("flags here...\n");
    printf("start address 0x%016lx\n\n", hdr->e_entry);
}

