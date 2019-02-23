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

int check_size(const char *filename, const char *prog, struct stat *s)
{
    if ((*s).st_size < 4)
        return (error("%s: %s: File truncated\n", prog, filename));
    if ((*s).st_size < (unsigned) sizeof(Elf64_Ehdr))
        return (error("%s: %s: File format not recognized\n", prog, filename));
    return (0);
}

static void *fd_to_hdr(int fd, const char *filename, const char *prog)
{
    struct stat s;
    void *buf;
    unsigned off;

    fstat(fd, &s);
    buf = mmap(NULL, (size_t) s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED)
        return (NULL);
    off = _E(buf, e_shoff) + _E(buf, e_shnum) * _E(buf, e_shentsize);
    if (check_size(filename, prog, &s) != 0)
        return (NULL);
    if (check_supported(buf, filename, prog) != 0)
        return (NULL);
    if (s.st_size < _E(buf, e_ehsize) || s.st_size < off) {
        fprintf(stderr, "%s: %s: File truncated\n", prog, filename);
        return (NULL);
    }
    return (buf);
}

static int is_dir(const char *prog, const char *filename)
{
    DIR *dir = opendir(filename);

    if (dir) {
        closedir(dir);
        error("%s: Warning: '%s' is a directory\n", prog, filename);
        return (1);
    }
    return (0);
}

static int check_access(const char *prog, const char *filename)
{
    if (access(filename, F_OK) != 0)
        return (error("%s: '%s': No such file\n", prog, filename));
    if (access(filename, R_OK) != 0)
        return (error("%s: %s: Permission denied\n", prog, filename));
    return (0);
}

void *file_to_hdr(const char *prog, const char *filename)
{
    int fd;
    void *hdr;

    if (check_access(prog, filename) != 0 || is_dir(prog, filename))
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error("%s: '%s': No such file\n", prog, filename);
        return (NULL);
    }
    hdr = fd_to_hdr(fd, filename, prog);
    close(fd);
    return (hdr);
}
