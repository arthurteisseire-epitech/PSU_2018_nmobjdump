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
    print_architecture(_E(hdr, e_machine));
    print_all_flags(hdr, _E(hdr, e_type), _E(hdr, e_shnum));
    print_address(_E(hdr, e_entry));
    print_sections(hdr, _E(hdr, e_shnum));
}

int main(int ac, const char *av[])
{
    return (exec_main(ac, av, "objdump", arch_exec));
}
