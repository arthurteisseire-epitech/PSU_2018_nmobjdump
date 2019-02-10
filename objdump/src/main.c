/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <elf.h>
#include "lib.h"

static void print_file_header(const Elf64_Ehdr *hdr)
{
    
}

static void exec(int ac, const char **av)
{
    Elf64_Ehdr *hdr;

    for (int i = 0; i < ac; ++i) {
        hdr = file_to_hdr("objdump", av[i]);
        print_file_header(hdr);
    }
}

int main(int ac, const char *av[])
{

    if (ac == 1)
        exec(2, (const char *[]) {"", "a.out"});
    else
        exec(ac, av);
    return (0);
}
