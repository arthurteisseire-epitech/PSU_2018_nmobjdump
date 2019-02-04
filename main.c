/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <unistd.h>
#include "func.h"

void toto()
{
    write(1, "toto", 4);
}

int main()
{
    toto();
    func();
}
