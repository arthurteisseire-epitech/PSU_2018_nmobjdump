/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include "nm.h"

int main(int ac, char **av)
{
    Elf64_Ehdr *hdr;

    if (ac != 1) {
        hdr = file_to_hdr(av[1]);
        if (hdr) {
            print_file_symbols(hdr);
            return (0);
        }
    }
    return (84);
}
