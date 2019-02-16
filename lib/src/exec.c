/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** exec.c
*/

#include "lib.h"

int exec(int ac, const char **av, const char *prog_name,
void (*ex)(const void *, const char *, int))
{
    void *hdr;
    int status = 0;

    for (int i = 1; i < ac; ++i) {
        hdr = file_to_hdr(prog_name, av[i]);
        if (hdr && check_supported(hdr, av[i]) == 0)
            ex(hdr, av[i], ac);
        else
            status = 84;
    }
    return (status);
}

