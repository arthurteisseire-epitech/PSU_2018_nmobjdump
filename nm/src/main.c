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
    if (!print_file_symbols(hdr, ((Elf64_Ehdr *) hdr)->e_shnum))
        printf("nm: %s: no symbols\n", filename);
}

int main(int ac, const char **av)
{
    return (exec_main(ac, av, "nm", arch_exec));
}
