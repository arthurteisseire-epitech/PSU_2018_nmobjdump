/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** symbol.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "nm.h"
#include "lib.h"

static const map_t types[] = {
        {'B', SHT_NOBITS,        SHF_ALLOC + SHF_WRITE},
        {'T', SHT_PROGBITS,      SHF_ALLOC + SHF_EXECINSTR},
        {'T', SHT_FINI_ARRAY,    SHF_ALLOC + SHF_WRITE},
        {'T', SHT_INIT_ARRAY,    SHF_ALLOC + SHF_WRITE},
        {'T', SHT_PREINIT_ARRAY, SHF_ALLOC + SHF_WRITE},
        {'D', SHT_PROGBITS,      SHF_ALLOC + SHF_WRITE},
        {'D', SHT_DYNAMIC,       SHF_ALLOC + SHF_WRITE},
        {'R', SHT_PROGBITS,      SHF_ALLOC},
        {0, 0, 0},
};

static char get_scope(const Elf64_Sym *sym, char c)
{
    if (ELF64_ST_BIND(sym->st_info) == STB_LOCAL)
        return ((char) tolower(c));
    return (c);
}

static char section_type(const Elf64_Shdr *section)
{
    for (int i = 0; types[i].c; ++i)
        if (types[i].type == section->sh_type &&
            types[i].flag == section->sh_flags)
            return (types[i].c);
    return ('?');
}

static char get_char_type(const Elf64_Sym *sym, const Elf64_Shdr *section)
{
    if (sym->st_shndx == SHN_ABS)
        return ('A');
    if (sym->st_shndx == SHN_COMMON)
        return ('C');
    if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
        if (ELF64_ST_TYPE(sym->st_info) == STT_OBJECT)
            return ('V');
        if (sym->st_shndx == SHN_UNDEF)
            return ('w');
        return ('W');
    }
    if (sym->st_shndx == SHN_UNDEF)
        return ('U');
    return (section_type(section));
}

void add_symbol(nm_t *nm, const Elf64_Ehdr *hdr, const Elf64_Shdr *section,
                size_t i)
{
    Elf64_Shdr *strtab = get_section(hdr, section->sh_link);
    Elf64_Sym *sym = get_symbol((void *) hdr + section->sh_offset, i);
    char *name = (char *) hdr + strtab->sh_offset + sym->st_name;
    char type;

    if (sym->st_info != STT_FILE && sym->st_info != STT_SECTION
        && sym->st_info != STT_NOTYPE) {
        type = get_char_type(sym, get_section(hdr, sym->st_shndx));
        if (type != '?') {
            nm->len++;
            nm->symbols = realloc(nm->symbols, nm->len * sizeof(symbol_t));
            nm->symbols[nm->len - 1].value = sym->st_value;
            nm->symbols[nm->len - 1].type = get_scope(sym, type);
            nm->symbols[nm->len - 1].name = name;
        }
    }
}
