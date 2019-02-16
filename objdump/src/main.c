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
    printf("\n%s:     file format elf64-x86-64\n", filename);
    print_header(hdr);
    print_sections(hdr, ((Elf64_Ehdr *) hdr)->e_shnum);
}

int main(int ac, const char *av[])
{
    return (exec_main(ac, av, "objdump", arch_exec));
}
