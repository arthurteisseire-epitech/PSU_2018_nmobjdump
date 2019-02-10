/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** map_file.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <elf.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "lib.h"

static Elf64_Ehdr *fd_to_hdr(int fd)
{
    struct stat s;
    void *buf;

    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf != MAP_FAILED)
        return (buf);
    perror("mmap");
    return (NULL);
}

static void check_directory(const char *prog, const char *filename)
{
    DIR *dir = opendir(filename);

    if (dir) {
        closedir(dir);
        error("%s: Warning: '%s' is a directory\n", prog, filename);
    }
}

Elf64_Ehdr *file_to_hdr(const char *prog, const char *filename)
{
    int fd;
    Elf64_Ehdr *hdr;

    check_directory(prog, filename);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error("%s: '%s': No such file\n", prog, filename);
    hdr = fd_to_hdr(fd);
    close(fd);
    if (!hdr)
        exit(84);
    return (hdr);
}

void check_elf_format(Elf64_Ehdr *hdr, const char *filename)
{
    const char magic[] = {0x7f, 'E', 'L', 'F'};

    if (memcmp(hdr->e_ident, magic, 4) != 0)
        error("%s: file format not recognized\n", filename);
}
