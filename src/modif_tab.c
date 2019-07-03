/*
** EPITECH PROJECT, 2019
** modif_tab.c
** File description:
** modify a tab
*/

#include "minishell2.h"

char **add_elem_tab(char **copy_env, char **tab_command)
{
    char **new_tab = malloc(sizeof(char *) *
                            (count_line_tab(copy_env) * 2) + 1);
    char **split_env;
    int i = 0;

    for (; copy_env[i] != NULL; i++) {
        split_env = my_str_to_wordtab(copy_env[i], '=');
        if (my_strcmp(tab_command[1], split_env[0]) == 0) {
            new_tab[i] = my_str_concast(tab_command[1], "=");
            if (tab_command[2] != NULL)
                new_tab[i] = my_str_concast(new_tab[i], tab_command[2]);
        } else
            new_tab[i] = copy_env[i];
    }
    new_tab[i] = my_str_concast(tab_command[1], "=");
    if (tab_command[2] != NULL)
        new_tab[i] = my_str_concast(new_tab[i], tab_command[2]);
    i++;
    new_tab[i] = NULL;
    return (new_tab);
}

char **remove_elem_tab(char **copy_env, char **tab_command)
{
    char **new_tab = malloc(sizeof(char *) *
                            (count_line_tab(copy_env) * 2) + 1);
    char **split_env;
    int i = 0;
    int j = 0;

    while (copy_env[i] != NULL) {
        split_env = my_str_to_wordtab(copy_env[i], '=');
        if (my_strcmp(tab_command[1], split_env[0]) == 0)
            i++;
        else {
            new_tab[j] = copy_env[i];
            j++;
            i++;
        }
    }
    new_tab[j] = NULL;
    return (new_tab);
}
