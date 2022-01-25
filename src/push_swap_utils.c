#include "../includes/push_swap.h"

t_stack    *ft_stacknew(int data)
{
    t_stack    *tmp;

    tmp = (t_stack *)malloc(sizeof(*tmp));
    if (!tmp)
        return (NULL);
    tmp->data = data;
    tmp->link = NULL;
    return (tmp);
}

void printStack(t_stack **s)
{
    if (s == NULL || !*s)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    printf("The stack elements are :");
    while (*s)
    {
        printf("\n%d ", (*s)->data);
        (*s) = (*s)->link;
    }
    printf("\n");
}


void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

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

t_stack    *fill_list(int ac, char **input)
{
    int i;
    t_stack *s;
    s = ft_stacknew(ft_atoi(input[0]));
    i = 1;
    while (ac > i)
    {
        push_front(&s,ft_atoi(input[i]));
        i++;
    }
    return (s);
}

int split_args(char ***strs, char **av, char *sep)
{
    int     ret;
    char    *str;
    char    *tmp;

    str = 0;
    while (*av)
    {
        if (!str)
            str = ft_strdup(*av++);
        else
        {
            tmp = str;
            str = ft_strjoin(str,sep);
            free(tmp);
            tmp = str;
            str = ft_strjoin(str, *av++);
            free(tmp);
        }
    }
    *strs = ft_split(str,*sep);
    free(str);
    ret = 0;
    while ((*strs)[ret])
        ret++;
    return (ret);
}
