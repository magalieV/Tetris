/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** SEPA_PRINT
*/

#include "printf_hd.h"
#include "separation_nb.h"

int sepa_one(char str, va_list list, between_t strg)
{
    int bol = 1;

    for (int j = 0; SEPARATION_NB[j].sort_2 != NULL; j++) {
        if (str == SEPARATION_NB[j].flag && bol == 1) {
            SEPARATION_NB[j].sort_2(list, str, strg);
            bol = 0;
        }
    }
    return (bol);
}

between_t sepa_two(char const *str, int *i, int *temp_2)
{
    int temp = 0;
    char *temp_3 = malloc(1);
    between_t strg;
    int j = *i;

    temp_3[0] = '\0';
    if (get_number(str[j + 1]) == 0) {
        temp = 0;
        strg = found_number((char *)str, ++j, &temp);
    } else {
        strg.str = my_strdup_print(temp_3);
        strg.space = 0;
        temp = 1;
    }
    *i = j;
    *temp_2 = temp;
    free(temp_3);
    return (strg);
}

int found_flag_less(between_t assign, int k)
{
    if (k > 0 && assign.str[k - 1] == '-')
        return (84);
    return (0);
}

int found_flag_point(between_t assign, int k)
{
    if (k > 0 && assign.str[k - 1] == '.')
        return (84);
    return (0);
}

void secu_str(char *str)
{
    char *temp = "diupsScoxXb";
    int bol = 0;
    int bol_2 = 0;

    for (int i = 0; str[i]; i++) {
        for (int j = 0; temp[j]; j++)
            test_secu(&bol, &bol_2, str[i], temp[j]);
    }
    if (bol_2 != 1)
        exit (84);
}
