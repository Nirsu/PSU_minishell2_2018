/*
** EPITECH PROJECT, 2019
** parse_env.c
** File description:
** parse env
*/

#include "minishell2.h"

int count_line_tab(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}

char **copy_double_tab(char **tab)
{
    int size_max = count_line_tab(tab);
    char **new_tab = malloc(sizeof(char *) * (size_max + 1) * 2);
    int y = 0;
    int x = 0;

    for (y = 0; tab[y] != NULL; y++) {
        new_tab[y] = malloc(sizeof(char) * my_strlen(tab[y]) + 1);
        for (x = 0; tab[y][x] != '\0'; x++) {
            new_tab[y][x] = tab[y][x];
        }
        new_tab[y][x] = '\0';
    }
    new_tab[y] = NULL;
    return (new_tab);
}

char *parse_env(char **envp, char *to_find)
{
    char **tab_env_tmp = my_str_to_wordtab(envp[0], '=');

    for (int i = 0; my_strcmp(tab_env_tmp[0], to_find) != 0; i++) {
        if (tab_env_tmp[0] == NULL)
            break;
        tab_env_tmp = my_str_to_wordtab(envp[i], '=');
    }
    if (tab_env_tmp[0] == NULL)
        return (NULL);
    return (tab_env_tmp[1]);
}
