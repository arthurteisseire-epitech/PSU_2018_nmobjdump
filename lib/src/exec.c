/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** exec.c
*/

#include "lib.h"

void exec_all_object_files(const void *hdr, const char *filename, int ac,
    void (*ex)(const void *, const char *, int))
{
    ex(hdr, filename, ac);
}

int exec(int ac, const char **av, const char *prog_name,
    void (*ex)(const void *, const char *, int))
{
    void *hdr;
    int status = 0;

    for (int i = 1; i < ac; ++i) {
        hdr = file_to_hdr(prog_name, av[i]);
        if (hdr)
            exec_all_object_files(hdr, av[i], ac, ex);
        else
            status = 84;
    }
    return (status);
}

int exec_main(int ac, const char **av, const char *prog_name,
    void (*ex)(const void *, const char *, int))
{
    if (ac == 1)
        return (exec(2, (const char *[]) {"", "a.out"}, prog_name, ex));
    return (exec(ac, av, prog_name, ex));
}

