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
    print_sections(hdr, _E(hdr, e_shnum));
}

int main(int ac, const char *av[])
{
    return (exec_main(ac, av, "objdump", arch_exec));
}
