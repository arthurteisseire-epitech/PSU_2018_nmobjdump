/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_header.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

static const map_t machines[] = {
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

static const flags_t type_flags[] = {
        {ET_DYN,  DYNAMIC + D_PAGED},
        {ET_EXEC, EXEC_P + D_PAGED},
        {ET_REL,  HAS_RELOC},
        {0, 0},
};

static const char *get_machine_name(Elf64_Half machine)
{
    for (int i = 0; machines[i].name; ++i)
        if (machine == machines[i].byte)
            return (machines[i].name);
    return machines[0].name;
}

unsigned int sym_flags(const Elf64_Ehdr *hdr)
{
    Elf64_Shdr *shdr = get_section_header(hdr);

    for (int i = 0; i < hdr->e_shnum; ++i)
        if (shdr[i].sh_type == SHT_SYMTAB)
            return (HAS_SYMS);
    return (NO_FLAGS);
}

unsigned int get_flags(const Elf64_Ehdr *hdr)
{
    unsigned int flags = sym_flags(hdr);

    for (int i = 0; type_flags[i].flag; i++)
        if (hdr->e_type == type_flags[i].type)
            return (type_flags[i].flag + flags);
    return (flags);
}

void print_header(const Elf64_Ehdr *hdr, const char *filename)
{
    unsigned flags = get_flags(hdr);

    printf("\n%s:     file format elf64-x86-64\n", filename);
    printf("architecture: %s, ", get_machine_name(hdr->e_machine));
    printf("flags 0x%08x:\n", flags);
    printf("flags here...\n");
    printf("start address 0x%016lx\n\n", hdr->e_entry);
}

