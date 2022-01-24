#include "../includes/push_swap.h"

void check_dup(char **av)
{
    int i;
    int j;
    char *dup;

    i = 0;
    while (av[i])
    {
        dup = ft_strdup(av[i]);
        j = 0;
        while (av[j])
        {
            if (i == j)
                j++;
            if (strcmp(dup,av[j]) == 0)
            {
                free(dup);
                printf("Values duplicated\n");
                exit(1);
            }
            j++;
        }
        free(dup);
        i++;
    }
    //printf("Values are not duplicated\n");
    //free(dup);
}