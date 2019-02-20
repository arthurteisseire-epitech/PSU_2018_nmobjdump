/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** sections.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "objdump.h"
#include "lib.h"

static bool is_section_printable(const void *hdr, size_t idx)
{
    return (sec(hdr, idx)->sh_type != SHT_NOBITS &&
    sec(hdr, idx)->sh_type != SHT_NULL &&
    strcmp(find_string(hdr, sec(hdr, idx)->sh_name), ".strtab") != 0 &&
    strcmp(find_string(hdr, sec(hdr, idx)->sh_name), ".symtab") != 0 &&
    strcmp(find_string(hdr, sec(hdr, idx)->sh_name), ".shstrtab") != 0 &&
    strcmp(find_string(hdr, sec(hdr, idx)->sh_name), ".bss") != 0 &&
    strcmp(find_string(hdr, sec(hdr, idx)->sh_name), ".rela.text") != 0 &&
    strcmp(find_string(hdr, sec(hdr, idx)->sh_name), ".rela.eh_frame") != 0 &&
    sec(hdr, idx)->sh_size != 0);
}

void print_sections(const void *hdr, size_t shnum)
{
    for (size_t i = 0; i < shnum; ++i)
        if (is_section_printable(hdr, i))
            print_section(hdr, i);
}
