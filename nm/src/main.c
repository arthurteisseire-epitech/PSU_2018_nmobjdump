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
#include "lib.h"

void exec(int ac, char **av)
{
    Elf64_Ehdr *hdr;

    for (int i = 1; i < ac; ++i) {
        if (ac >= 3)
            printf("\n%s:\n", av[i]);
        hdr = file_to_hdr("nm", av[i]);
        check_elf_format(hdr, av[i]);
        if (!print_file_symbols(hdr))
            printf("nm: %s: no symbols\n", av[i]);
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
