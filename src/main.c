/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nm.h"

void check_elf_format(Elf64_Ehdr *hdr, const char *filename)
{
    const char magic[] = {0x7f, 'E', 'L', 'F'};

    if (memcmp(hdr->e_ident, magic, 4) != 0) {
        fprintf(stdout, "nm: %s: file format not recognized\n", filename);
        exit(84);
    }
}

int main(int ac, char **av)
{
    Elf64_Ehdr *hdr;

    if (ac != 1) {
        hdr = file_to_hdr(av[1]);
        if (hdr) {
            check_elf_format(hdr, av[1]);
            print_file_symbols(hdr);
            return (0);
        }
    }
    return (84);
}
