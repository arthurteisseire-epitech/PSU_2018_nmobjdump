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

Elf64_Ehdr *file_to_hdr(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    Elf64_Ehdr *hdr;

    if (fd == -1)
        return (NULL);
    hdr = fd_to_hdr(fd);
    close(fd);
    return (hdr);
}