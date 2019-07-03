/*
** EPITECH PROJECT, 2018
** my_system_call.c
** File description:
** basic function
*/

#include "minishell2.h"

size_t my_strlen(const char *str)
{
    size_t len = 0;

    if (!str)
        return (len);
    for (; *str++; ++len);
    return (len);
}

void my_putstr(const char * const str)
{
    write(STDOUT_FILENO, str, my_strlen(str));
}

void my_putstderr(const char * const str)
{
    write(STDERR_FILENO, str, my_strlen(str));
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}

char *my_str_concast(char *str1, char *str2)
{
    char *str3 = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)) + 1);
    int j = 0;

    for (int i = 0; str1[i] != '\0'; i++, j++)
        str3[j] = str1[i];
    for (int i = 0; str2[i] != '\0'; i++, j++)
        str3[j] = str2[i];
    str3[j] = '\0';
    return (str3);
}
