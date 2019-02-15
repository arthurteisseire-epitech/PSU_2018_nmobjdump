/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** error_handling.c
*/

#include <stdbool.h>
#include <elf.h>
#include <string.h>
#include "lib.h"

int check_file_format(Elf64_Ehdr *hdr, const char *filename)
{
    const char magic[] = {0x7f, 'E', 'L', 'F'};

    if (memcmp(hdr->e_ident, magic, 4) != 0)
        return (error("%s: file format not recognized\n", filename));
    return (0);
}

int check_supported(Elf64_Ehdr *hdr, const char *filename)
{
    int status = check_file_format(hdr, filename);

    if (status != 0)
        return (status);
    if (hdr->e_ident[EI_CLASS] == ELFCLASSNONE)
        return (error("Unknown architecture\n"));
    if (hdr->e_ident[EI_DATA] == ELFDATANONE)
        return (error("Unknown byte order\n"));
    if (hdr->e_ident[EI_VERSION] == EV_NONE)
        return (error("Unknown version\n"));
    if (hdr->e_machine == EM_NONE)
        return (error("Unknown machine\n"));
    if (hdr->e_type == ET_NONE)
        return (error("Unknown file type"));
    return (0);
}
