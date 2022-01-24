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
            else if (strcmp(dup,av[j]) == 0)
            {
                free(dup);
                ft_exit_ps("Values duplicated !",1);
            }
            else
                j++;
        }
        free(dup);
        i++;
    }
}