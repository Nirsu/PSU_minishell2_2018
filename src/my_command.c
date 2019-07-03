/*
** EPITECH PROJECT, 2019
** my_command
** File description:
** my command
*/

#include "minishell2.h"

int my_cd(char **tab_command, char **copy_env)
{
    char *path = tab_command[1];
    char *get_cwd = malloc(sizeof(char) * 255);

    if (my_strcmp(tab_command[1], "-") == 0) {
        path = parse_env(copy_env, "OLDPWD");
        if (path == NULL)
                path = getcwd(get_cwd, 255);
    }
    if (chdir(path) == -1) {
        perror(tab_command[1]);
        return (-1);
    }
    return (0);
}

int my_setenv(char **tab_command, char **copy_env)
{
    char **new_env;
    char *tmp = NULL;
    int i = 0;

    if (tab_command[1] == NULL)
        return (0);
    new_env = add_elem_tab(copy_env, tab_command);
    for (; new_env[i] != NULL; i++) {
        tmp = malloc(sizeof(char) * my_strlen(new_env[i]) + 1);
        copy_env[i] = my_memcpy(tmp, new_env[i], my_strlen(new_env[i]) + 1);
    }
    copy_env[i] = NULL;
    return (0);
}

int my_unsetenv(char **tab_command, char **copy_env)
{
    char **new_env = remove_elem_tab(copy_env, tab_command);
    char *tmp = NULL;
    int i = 0;

    for (; new_env[i] != NULL; i++) {
        tmp = malloc(sizeof(char) * my_strlen(new_env[i]) + 1);
        copy_env[i] = my_memcpy(tmp, new_env[i], my_strlen(new_env[i]) + 1);
    }
    copy_env[i] = NULL;
    return (0);
}

int my_exit(char **tab_command, char **copy_env)
{
    free_tab(copy_env);
    return (0);
}
