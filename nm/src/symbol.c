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
        {'D', SHT_PROGBITS,      SHF_ALLOC + SHF_WRITE},
        {'D', SHT_DYNAMIC,       SHF_ALLOC + SHF_WRITE},
        {'R', SHT_PROGBITS,      SHF_ALLOC},
        {0, 0, 0},
};

static char get_scope(const void *hdr, const void *sym, char c)
{
    if (ELF64_ST_BIND(_SYM(hdr, sym, st_info)) == STB_LOCAL)
        return ((char) tolower(c));
    return (c);
}

static char section_type(const void *hdr, size_t idx)
{
    for (int i = 0; types[i].c; ++i)
        if (types[i].type == _SI(hdr, idx, sh_type) &&
            types[i].flag == _SI(hdr, idx, sh_flags))
            return (types[i].c);
    return ('?');
}

static char get_char_type(const void *hdr, const void *sym)
{
    if (_SYM(hdr, sym, st_shndx) == SHN_ABS)
        return ('A');
    if (_SYM(hdr, sym, st_shndx) == SHN_COMMON)
        return ('C');
    if (ELF64_ST_BIND(_SYM(hdr, sym, st_info)) == STB_WEAK) {
        if (ELF64_ST_TYPE(_SYM(hdr, sym, st_info)) == STT_OBJECT)
            return (_SYM(hdr, sym, st_shndx) == SHN_UNDEF ? 'v' : 'V');
        return (_SYM(hdr, sym, st_shndx) == SHN_UNDEF ? 'w' : 'W');
    }
    if (_SYM(hdr, sym, st_shndx) == SHN_UNDEF)
        return ('U');
    return (section_type(hdr, _SYM(hdr, sym, st_shndx)));
}

void add_symbol(nm_t *nm, const void *hdr, size_t idx, size_t i)
{
    size_t str_off = _SI(hdr, _SI(hdr, idx, sh_link), sh_offset);
    const void *sym = get_symbol(hdr, idx, i);
    char *name = (char *) hdr + str_off + _SYM(hdr, sym, st_name);
    char type;

    if (_SYM(hdr, sym, st_name) != 0 &&
    ELF64_ST_TYPE(_SYM(hdr, sym, st_info)) != STT_FILE) {
        type = get_char_type(hdr, sym);
        if (type != '?') {
            nm->len++;
            nm->symbols = realloc(nm->symbols, nm->len * sizeof(symbol_t));
            nm->symbols[nm->len - 1].value = _SYM(hdr, sym, st_value);
            nm->symbols[nm->len - 1].type = get_scope(hdr, sym, type);
            nm->symbols[nm->len - 1].name = name;
        }
    }
}
