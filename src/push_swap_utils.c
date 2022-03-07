/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:10:58 by izail             #+#    #+#             */
/*   Updated: 2022/02/08 11:11:08 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int ft_stacksize(t_stack *s)
{
    int ret;

    ret = 0;
    while (s)
    {
        s = s->link;
        ret++;
    }
    return(ret);
}

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

int ft_abs(int  n)
{
    int abs;

    if (n < 0)
        abs = -1 * n;
    else
        abs = n;
    return (abs);
}

long    ft_atol(char *str)
{
    long    nbr;
    long    signe;

    nbr = 0;
    signe = 1;
    while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		signe = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * signe);
}

int    check_if_int(char *str)
{
    int i;

    i = 0;
    if (str[i] == '+' || str[i] == '-')
            i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    if (( ft_atol(str) < INT_MIN ) || ( ft_atol(str) > INT_MAX ))
        return (0);
    return (1);
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
            else if (strcmp(dup,av[j]) == 0 || (ft_atoi(dup) == ft_atoi(av[j])))
            {
                free(dup);
                ft_exit_ps("Values duplicated !",2);
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
    
    i = ac - 1;
    
    while (i >= 0)
    {   
        if (!check_if_int(input[i]))
            ft_exit_ps("Error\n",2);
        if (i == (ac - 1))
            s = ft_stacknew(ft_atoi(input[i]));
        else
            push_front(&s,ft_atoi(input[i]));
        i--;
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

// int	is_valid(char **strs)
// {
// 	int	i;
// 	int	tmp;
// 	int	ret;
// 	int	*nums;

// 	i = 0;
// 	ret = 0;
// 	while (strs[i])
// 		if (!is_int(strs[i++]))
// 			return (ret);
// 	nums = malloc(sizeof(int) * i);
// 	if (!nums)
// 		return (ret);
// 	tmp = i;
// 	while (i--)
// 		nums[i] = ft_atoi(strs[i]);
// 	if (!has_duplicate(nums, tmp))
// 		ret = 1;
// 	free(nums);
// 	return (ret);
// }