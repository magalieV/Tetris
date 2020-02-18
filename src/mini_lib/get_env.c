/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "header.h"

char *my_strcp(char const *env, char *tmp, int size)
{
    int i = 0;
    int k = 0;

    tmp = malloc(sizeof(char) * (size + 1));
    for (i = 0; i < size; i++) {
        if (env && env[i])
            tmp[k++] = env[i];
    }
    tmp[k++] = '\0';
    return (tmp);
}

char *recup_env(char const *str)
{
    int i = 0;
    int size = 0;
    int k = 0;
    char *new = NULL;

    for (i = 0; str[i]; i++) {
        if (str[i] == '=')
            break;
    }
    for (size = 0; str[size]; size++);
    size -= i;
    new = malloc(sizeof(char) * (size + 1));
    for (int j = i + 1; str[j]; j++)
        new[k++] = str[j];
    new[k] = '\0';
    return (new);
}

int found_line_of_env(char *const *env, int size, char const *path_search)
{
    int i = 0;
    char *tmp = NULL;
    char **cp = (char **)env;

    for (i = 0; env[i]; i++) {
        tmp = my_strcp(env[i], tmp, size);
        if (my_strncmp(tmp, path_search) == 0)
            break;
        if (tmp)
            free(tmp);
    }
    if ((tmp && my_strncmp(tmp, path_search) != 0) || !tmp)
        return (-1);
    if (tmp)
        free(tmp);
    return (i);
}

char *get_env(char *const *env, char const *path_search)
{
    int size = 0;
    char *env_found = NULL;
    int size_env = 0;
    char *final_env = NULL;
    int i = 0;
    int j = 0;

    for (size = 0; path_search[size]; size++);
    i = found_line_of_env(env, size, path_search);
    if (i == -1)
        return (NULL);
    for (size_env = 0; env[i][size_env]; size_env++);
    env_found = malloc(sizeof(char) * (size_env + 1));
    for (j = 0; env[i][j]; j++)
        env_found[j] = env[i][j];
    env_found[j] = '\0';
    final_env = recup_env(env_found);
    if (env_found)
        free(env_found);
    return (final_env);
}
