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

static const char *message = "%s: %s: File format not recognized\n";

static int check_file_format(const void *hdr, const char *filename,
const char *prog)
{
    const char magic[] = {0x7f, 'E', 'L', 'F'};

    if (memcmp(_E(hdr, e_ident), magic, 4) != 0)
        return (error(message, prog, filename));
    return (0);
}

int check_supported(const void *hdr, const char *filename, const char *prog)
{
    int status = check_file_format(hdr, filename, prog);

    if (status != 0)
        return (status);
    if (get_arch(hdr) == 0)
        return (error(message, prog, filename));
    if (_E(hdr, e_ident)[EI_DATA] == ELFDATANONE)
        return (error(message, prog, filename));
    if (_E(hdr, e_ident)[EI_VERSION] == EV_NONE)
        return (error(message, prog, filename));
    if (_E(hdr, e_machine) == EM_NONE)
        return (error(message, prog, filename));
    if (_E(hdr, e_type) == ET_NONE)
        return (error(message, prog, filename));
    return (0);
}
