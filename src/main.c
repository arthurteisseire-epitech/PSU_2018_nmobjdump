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

static inline Elf64_Sym *elf_sym(Elf64_Shdr *hdr, int idx)
{
    return (Elf64_Sym *)&hdr[idx];
}

static void printSymbols(char *section_string_table)
{
    if (section_string_table == NULL)
        printf("NULL\n");
    else
        printf("%s\n", section_string_table);
    printf("symbol table\n");
}

static Elf64_Sym *elf_find_sym(Elf64_Ehdr *elf)
{
    Elf64_Shdr *current_section = elf_sheader(elf);

    for (int i = 0; i < elf->e_shnum; ++i) {
        if (current_section->sh_type == SHT_SYMTAB || current_section->sh_type == SHT_DYNSYM) {
            printf("%lu\n", current_section->sh_size);
            printf("%lu\n", sizeof(Elf64_Sym));
            printf("%lu\n", current_section->sh_entsize);
            printSymbols(elf_find_string(elf, elf_sym(current_section, 0)->st_name));
            return ((Elf64_Sym *) current_section);
        }
        current_section = (void *) current_section + elf->e_shentsize;
    }
    return (NULL);
}

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
