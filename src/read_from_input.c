#include "../includes/push_swap.h"

t_stack    *fill_list(int ac, char **input)
{
    int i;
    t_stack *s;
    s = ft_stacknew(ft_atoi(input[1]));
    i = 2;
    while (ac > i)
    {
        push_front(&s,ft_atoi(input[i]));
        i++;
    }
    return (s);
}