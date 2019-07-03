/*
** EPITECH PROJECT, 2019
** start_msh.c
** File description:
** start minishell2
*/

#include "minishell2.h"
#include <sys/types.h>
#include <sys/wait.h>

void catch_seg(char **tab_command, int pid)
{
    int status = 0;

    if (pid == 0) {
        execve(tab_command[0], tab_command, NULL);
        wait(0);
    }
    if (waitpid(pid, &status, WCONTINUED | WUNTRACED) == -1)
        exit(84);
    if (WIFSIGNALED(status)) {
        if (WCOREDUMP(status))
            my_putstr("Segmentation fault (core dumped)\n");
        else
            my_putstr("Segmentation fault\n");
    }
}

int exec_command(char *command, char **copy_env, int pid)
{
    char **tab_command = my_str_to_wordtab(command, ' ');
    char *line_path = parse_env(copy_env, "PATH");
    char **exec_path = my_str_to_wordtab(line_path, ':');
    char *new_exec_path = NULL;
    int return_execve = 0;

    if (pid == 0) {
        for (int i = 0; exec_path[i] != NULL; i++) {
            new_exec_path = my_str_concast(exec_path[i], "/");
            new_exec_path = my_str_concast(new_exec_path, tab_command[0]);
            return_execve = execve(new_exec_path, tab_command, copy_env);
        }
        if (return_execve == -1) {
            my_putstderr(tab_command[0]);
            my_putstderr(": Command not found.\n");
        }
        exit(0);
    }
    wait(0);
    return (0);
}

int start_command(char **av, char *command, char **copy_env)
{
    int i = 0;
    int pid = 0;
    char **tab_command = my_str_to_wordtab(command, ' ');
    char *verif_tab_fonction[4] = {"cd", "setenv", "unsetenv", "exit"};
    int (*tab_fonction[4])(char **, char **) = {my_cd, my_setenv,
                                                my_unsetenv, my_exit};

    for (; my_strcmp(tab_command[0], verif_tab_fonction[i]) != 0 && i < 4; i++);
    if (i == 4) {
        pid = fork();
        if (pid == -1)
            return (-1);
        if (tab_command[0][0] == '.')
            catch_seg(tab_command, pid);
        else
            exec_command(command, copy_env, pid);
    }
    else
        return (tab_fonction[i](tab_command, copy_env));
    return (0);
}

int start_minishell(int ac, char **av, char **envp)
{
    char *command = NULL;
    char *epu_command = NULL;
    char **copy_env = copy_double_tab(envp);

    while (my_strcmp(command, "exit") != 0) {
        my_putstr("Meru $> ");
        command = my_get_next_line(0);
        if (command == NULL)
            return (-1);
        epu_command = epu_str(command);
        start_command(av, epu_command, copy_env);
    }
    return (0);
}
