/*
** EPITECH PROJECT, 2018
** epu_str.c
** File description:
** purify a string
*/

#include "minishell2.h"

int is_alpha(const char cara)
{
    if ((cara >= 'a' && cara <= 'z') || (cara >= 'A' && cara <= 'Z'))
        return (0);
    if (cara == '.' || cara == '/')
        return (0);
    return (1);
}

char *epu_str(char *str)
{
    int i = 0;
    int j = 0;
    int space = 0;
    char *str_2 = malloc(sizeof(char) * my_strlen(str) + 1);

    for (;is_alpha(str[i]) != 0; i++);
    for (;str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            if (space == 1)
                str_2[j++] = ' ';
            space = 0;
            str_2[j++] = str[i];
        }
        else if (space == 0)
            space = 1;
    }
    str_2[j] = '\0';
    return (str_2);
}
