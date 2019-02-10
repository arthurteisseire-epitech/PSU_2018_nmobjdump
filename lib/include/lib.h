/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** lib.h
*/

#ifndef PSU_2018_NMOBJDUMP_LIB_H
#define PSU_2018_NMOBJDUMP_LIB_H

void check_elf_format(Elf64_Ehdr *hdr, const char *filename);
Elf64_Ehdr *file_to_hdr(const char *prog, const char *filename);

void error(const char *message, ...);

#endif
