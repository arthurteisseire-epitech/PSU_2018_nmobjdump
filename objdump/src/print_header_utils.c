/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print_header_utils.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

static const format_t machines[] = {
        {EM_X86_64, "i386:x86-64", "elf64-x86-64"},
        {EM_386,    "i386",        "elf32-i386"},
        {0, NULL, NULL}
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
    if (flag_names[i].machine) {
        if (flags && flags >= flag_names[i].byte) {
            print_flags(flags - flag_names[i].byte, i + 1, ", ");
            printf("%s%s", flag_names[i].machine, comma);
        } else {
            print_flags(flags, i + 1, comma);
        }
    }
}

const char *get_machine_name(Elf64_Half machine)
{
    for (int i = 0; machines[i].machine; ++i)
        if (machine == machines[i].byte)
            return (machines[i].machine);
    return (machines[0].machine);
}

const char *get_format(Elf64_Half machine)
{
    for (int i = 0; machines[i].arch; ++i)
        if (machine == machines[i].byte)
            return (machines[i].arch);
    return (machines[0].arch);
}

unsigned int sym_flags(const void *hdr, size_t shnum)
{
    for (size_t i = 0; i < shnum; ++i)
        if (_SI(hdr, i, sh_type) == SHT_SYMTAB ||
            _SI(hdr, i, sh_type) == SHT_DYNSYM)
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
