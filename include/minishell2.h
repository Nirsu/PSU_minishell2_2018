/*
** EPITECH PROJECT, 2019
** minishell2.h
** File description:
** minishell 2 header
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_
#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//my_system_call.c
void my_putstr(const char * const str);
void my_putstderr(const char * const str);
int my_strcmp(char *s1, char *s2);
char *my_str_concast(char *str1, char *str2);
size_t my_strlen(const char *str);

//start_msh.c
int start_minishell(int ac, char **av, char **envp);

//my_get_next_line.c
char *my_get_next_line(int fd);

//my_command.c
int my_cd(char **tab_command, char **copy_env);
int my_setenv(char **tab_command, char **copy_env);
int my_unsetenv(char **tab_command, char **copy_env);
int my_exit(char **tab_command, char **copy_env);

//my_str_to_wordtab.c
char **my_str_to_wordtab(char *str, char separator);
void free_tab(char **tab);

//parse_env.c
char *parse_env(char **envp, char *to_find);
char **copy_double_tab(char **tab);
int count_line_tab(char **tab);

//epu_str.c
char *epu_str(char *str);

//modif_tab.c
char **add_elem_tab(char **copy_env, char **tab_command);
char **remove_elem_tab(char **copy_env, char **tab_command);

//my_memcpy.c
void *my_memcpy(void *dest, const void *src, size_t len);
#endif
