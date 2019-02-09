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

    if (memcmp(hdr->e_ident, magic, 4) != 0)
        error("%s: file format not recognized\n", filename);
}

void exec(int ac, char **av)
{
    Elf64_Ehdr *hdr;

    for (int i = 1; i < ac; ++i) {
        if (ac >= 3)
            printf("\n%s:\n", av[i]);
        hdr = file_to_hdr(av[i]);
        check_elf_format(hdr, av[i]);
        print_file_symbols(hdr);
    }
}

int main(int ac, char **av)
{
    if (ac == 1)
        exec(2, (char *[]) {"", "a.out"});
    else
        exec(ac, av);
    return (0);
}
