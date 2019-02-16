/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

static void exec_with_arch(const void *hdr, const char *filename)
{
    print_header(hdr, filename);
    print_sections(hdr, ((Elf64_Ehdr *) hdr)->e_shnum);
}

static int exec(int ac, const char **av)
{
    void *hdr;
    int status = 0;

    for (int i = 1; i < ac; ++i) {
        hdr = file_to_hdr("objdump", av[i]);
        if (hdr && check_supported(hdr, av[i]) == 0)
            exec_with_arch(hdr, av[i]);
        else
            status = 84;
    }
    return (status);
}

int main(int ac, const char *av[])
{
    if (ac == 1)
        return (exec(2, (const char *[]) {"", "a.out"}));
    return (exec(ac, av));
}
