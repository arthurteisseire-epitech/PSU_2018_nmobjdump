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

static void arch_exec(const void *hdr, const char *filename, int ac)
{
    if (ac >= 3)
        printf("\n%s:\n", filename);
    if (!print_file_symbols(hdr))
        printf("nm: %s: no symbols\n", filename);
}

int exec(int ac, const char **av, const char *prog_name,
void (*ex)(const void *, const char *, int))
{
    void *hdr;
    int status = 0;

    for (int i = 1; i < ac; ++i) {
        hdr = file_to_hdr(prog_name, av[i]);
        if (hdr && check_supported(hdr, NULL) == 0)
            ex(hdr, av[i], ac);
        else
            status = 84;
    }
    return (status);
}

int main(int ac, const char **av)
{
    const char *prog_name = "nm";

    if (ac == 1)
        return (exec(2, (const char *[]) {"", "a.out"}, prog_name, arch_exec));
    return (exec(ac, av, prog_name, arch_exec));
}
