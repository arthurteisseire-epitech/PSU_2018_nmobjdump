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

int exec(int ac, char **av)
{
    Elf64_Ehdr *hdr;
    int status = 0;

    for (int i = 1; i < ac; ++i) {
        if (ac >= 3)
            printf("\n%s:\n", av[i]);
        hdr = file_to_hdr("nm", av[i]);
        if (!hdr || check_supported(hdr, NULL) == 84) {
            status = 84;
            continue;
        }
        if (!print_file_symbols(hdr))
            printf("nm: %s: no symbols\n", av[i]);
    }
    return (status);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (exec(2, (char *[]) {"", "a.out"}));
    return (exec(ac, av));
}
