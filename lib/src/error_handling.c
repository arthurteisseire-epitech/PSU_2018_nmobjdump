/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** error_handling.c
*/

#include <stdbool.h>
#include <elf.h>
#include "lib.h"

int check_supported(Elf32_Ehdr *hdr)
{
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
