/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include <dlfcn.h>
#include <stdio.h>
#include <gnu/lib-names.h>

int main(int ac, char *av[])
{
    void (*f)();
    void *handle;

    if (ac == 1)
        return (84);
    handle = dlopen(av[1], RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return (84);
    }

    f = dlsym(handle, "about");
    f();
    dlclose(handle);
    return (0);
}
