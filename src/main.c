/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "nm.h"

void printInfos(Elf64_Ehdr *elf)
{
    Elf64_Sym *sym = elf_find_sym(elf);

    printSymbols(elf_find_string(elf, sym->st_name));
}

void mapFile(int fd, char *filename)
{
    struct stat s;
    void *buf;
    Elf64_Ehdr *elf;

    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf != MAP_FAILED) {
        printf("mmap (%s) : %08lx\n", filename, buf);
        elf = buf;
        printInfos(elf);
    } else {
        perror("mmap");
    }
}

int main(int ac, char **av)
{
    int fd;

    if (ac == 1)
        return (84);
    fd = open(av[1], O_RDONLY);
    if (fd != -1) {
        mapFile(fd, av[1]);
        close(fd);
    }
}
