/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main minishell2
*/

#include "minishell2.h"

int main(int ac, char **av, char **envp)
{
    if (envp[0] == NULL) {
        my_putstr("No 'env'");
        return (84);
    }
    start_minishell(ac, av, envp);
    return (0);
}
