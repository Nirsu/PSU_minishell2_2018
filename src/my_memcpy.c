/*
** EPITECH PROJECT, 2019
** my_memcpy
** File description:
** copy 2 string with pointeur
*/

#include "minishell2.h"

void *my_memcpy(void *dest, const void *src, size_t len)
{
    char *copy_dest = dest;
    const char *copy_src = src;

    for (size_t i = 0; i < len; i++)
        *copy_dest++ = *copy_src++;
    return (dest);
}
