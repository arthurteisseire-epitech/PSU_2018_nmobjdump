/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <stdio.h>
#include "objdump.h"
#include "lib.h"

static void arch_exec(const void *hdr, const char *filename,
__attribute((unused)) int ac)
{
    print_header(hdr, filename);
    print_sections(hdr, ((Elf64_Ehdr *) hdr)->e_shnum);
}

int main(int ac, const char *av[])
{
    const char *prog_name = "objdump";

    if (ac == 1)
        return (exec(2, (const char *[]) {"", "a.out"}, prog_name, arch_exec));
    return (exec(ac, av, prog_name, arch_exec));
}
