/*
** EPITECH PROJECT, 2019
** str_to_wordtab
** File description:
** convert a char * to a char **
*/

#include "minishell2.h"

void free_tab(char **tab)
{
    for (int y = 0; tab[y] != NULL; y++) {
        free(tab[y]);
        tab[y] = NULL;
        y++;
    }
}

int count_word(char *str, char separator)
{
    int j = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == separator || str[i + 1] == '\0')
            j++;
    }
    return (j);
}

int verif_array(char const str, char const separator)
{
    if (str == separator || str == '\0' || str == '\n' || str == '\t')
        return (1);
    return (0);
}

char *copy_word(char *tab, int *j, char const *str, char separator)
{
    int i = 0;
    int tmp_size = 0;
    int save = 0;

    for (; verif_array(str[*j], separator) == 1 && str[*j] != '\0'; (*j)++);
    for (; verif_array(str[*j], separator) == 0 && str[*j] != '\0';
         tmp_size++, (*j)++);
    tab = malloc(sizeof(char) * tmp_size + 1);
    if (tab == NULL)
        return (NULL);
    save = *j - tmp_size;
    for (; save != *j; save++, i++)
        tab[i] = str[save];
    tab[i] = '\0';
    return (tab);
}

char **my_str_to_wordtab(char *str, char separator)
{
    int nbr_word = 0;
    char **tab = malloc(sizeof(char *) * (nbr_word + 1) * 2);
    int i = 0;
    int j = 0;

    if (str == NULL) {
        tab[0] = NULL;
        return (tab);
    }
    nbr_word = count_word(str, separator);
    for (; i != nbr_word; i++)
        tab[i] = copy_word(tab[i], &j, str, separator);
    tab[i] = NULL;
    return (tab);
}
