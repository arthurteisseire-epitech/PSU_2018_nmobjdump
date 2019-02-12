/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

static int exec(int ac, const char **av)
{
    Elf64_Ehdr *hdr;
    int status = 0;

    for (int i = 1; i < ac; ++i) {
        hdr = file_to_hdr("objdump", av[i]);
        if (!hdr || check_elf_format(hdr, av[i]) == 84) {
            status = 84;
            continue;
        }
        print_header(hdr, av[i]);
        print_sections(hdr);
    }
    return (status);
}

int main(int ac, const char *av[])
{

    if (ac == 1)
        return (exec(2, (const char *[]) {"", "a.out"}));
    return (exec(ac, av));
}
