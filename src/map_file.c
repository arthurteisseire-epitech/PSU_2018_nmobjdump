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
#include "nm.h"

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

static void check_directory(const char *filename)
{
    DIR *dir = opendir(filename);

    if (dir) {
        closedir(dir);
        error("nm: Warning: '%s' is a directory\n", filename);
    }
}

Elf64_Ehdr *file_to_hdr(const char *filename)
{
    int fd;
    Elf64_Ehdr *hdr;

    check_directory(filename);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error("nm: '%s': No such file\n", filename);
    hdr = fd_to_hdr(fd);
    close(fd);
    if (!hdr)
        exit(84);
    return (hdr);
}
