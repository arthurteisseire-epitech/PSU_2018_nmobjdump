/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** print.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int error(const char *message, ...)
{
    va_list ap;

    va_start(ap, message);
    vfprintf(stdout, message, ap);
    va_end(ap);
    return (84);
}
