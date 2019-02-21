/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_header_utils.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

static const map_t machines[] = {
        {EM_X86_64,      "i386:x86-64"},
        {EM_NONE,        "None"},
        {EM_M32,         "WE32100"},
        {EM_SPARC,       "Sparc"},
        {EM_386,         "i386"},
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

static const map_t flag_names[] = {
        {D_PAGED,    "D_PAGED"},
        {DYNAMIC,    "DYNAMIC"},
        {HAS_LOCALS, "HAS_LOCAL"},
        {HAS_SYMS,   "HAS_SYMS"},
        {HAS_DEBUG,  "HAS_DEBUG"},
        {EXEC_P,     "EXEC_P"},
        {HAS_RELOC,  "HAS_RELOC"},
        {NO_FLAGS,   "NO_FLAGS"},
        {0, NULL},
};

void print_flags(unsigned int flags, unsigned int i, char *comma)
{
    if (flag_names[i].name) {
        if (flags && flags >= flag_names[i].byte) {
            print_flags(flags - flag_names[i].byte, i + 1, ", ");
            printf("%s%s", flag_names[i].name, comma);
        } else {
            print_flags(flags, i + 1, comma);
        }
    }
}

const char *get_machine_name(Elf64_Half machine)
{
    for (int i = 0; machines[i].name; ++i)
        if (machine == machines[i].byte)
            return (machines[i].name);
    return machines[0].name;
}

unsigned int sym_flags(const void *hdr, size_t shnum)
{
    for (size_t i = 0; i < shnum; ++i)
        if (_SI(hdr, i, sh_type) == SHT_SYMTAB)
            return (HAS_SYMS);
    return (NO_FLAGS);
}

unsigned int get_flags(const void *hdr, uint16_t elf_type, size_t shnum)
{
    unsigned int flags = sym_flags(hdr, shnum);

    for (int i = 0; type_flags[i].flag; i++)
        if (elf_type == type_flags[i].type)
            return (type_flags[i].flag + flags);
    return (flags);
}
