/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:18 by izail             #+#    #+#             */
/*   Updated: 2022/02/12 12:38:00 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = (*stack_a)->data;
	num_2 = (*stack_a)->link->data;
	num_3 = (*stack_a)->link->link->data;
	if (stack_a == NULL)
		return ;
	if (num_1 > num_2 && num_1 < num_3)
		ft_run(&ft_sa,stack_a,stack_b);
	else if (num_1 > num_2 && num_2 > num_3)
	{
		ft_run(&ft_sa, stack_a, stack_b);
		ft_run(&ft_rra, stack_a, stack_b);
	}
	else if (num_1 > num_2 && num_2 < num_3)
		ft_run(&ft_ra,stack_a, stack_b);
	else if (num_1 < num_2 && num_2 > num_3)
	{
		ft_run(&ft_sa, stack_a, stack_b);
		ft_run(&ft_ra, stack_a, stack_b);
	}
	else if (num_1 > num_2 && num_2 > num_3)
		ft_run(&ft_rra,stack_a, stack_b);
}

void	sort_stack(t_stack *s)
{
    t_stack *node;
    t_stack *tmp;
    int     var;

    node = s;
	tmp = NULL;
	while (node != NULL)
	{
		tmp = node;
		while (tmp->link != NULL)
		{
			if (tmp->data > tmp->link->data)
			{
				// printf("tmp->link == %d\n", tmp->link->data);
				var = tmp->data;
				tmp->data = tmp->link->data;
				tmp->link->data = var;
				// printf("var == %d\n", var);
			}
			tmp = tmp->link;
		}
		node = node->link;
	}
}

// void	sort_big(t_stack **stack_a, t_stack **stack_b)
// {

// }

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	ft_place_smallest_first(stack_a,stack_b);
	ft_run(&ft_pb,stack_a, stack_b);
	ft_place_smallest_first(stack_a,stack_b);
	ft_run(&ft_pb,stack_a, stack_b);
	sort_3(stack_a,stack_b);
	ft_run (&ft_pa,stack_a, stack_b);
	ft_run (&ft_pa,stack_a, stack_b);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	ft_place_smallest_first(stack_a,stack_b);
	ft_run(&ft_pb,stack_a, stack_b);
	sort_3(stack_a,stack_b);
	ft_run (&ft_pa,stack_a, stack_b);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		ft_place_smallest_first(stack_a, stack_b);
		ft_run(&ft_pb,stack_a, stack_b);
	}
	while (*stack_b)
		ft_run(&ft_pa,stack_a, stack_b); 	
}

int     is_sorted(t_stack **s)
{
    while ((*s)->link != NULL)
    {
        if ((*s)->data > (*s)->link->data)
            return (0);
        (*s) = (*s)->link;
    }
    return (1);
}

// int *set_groups(t_stack *stack)
// {
//     int count;
//     int size;
//     t_stack *tab;
//     int i;
//     int find;
// 	int traverse;

// 	size = ft_stacksize(stack);
//     tab = (t_stack)malloc(size);
//     i = 0;
//     while (i < size)
//     {
//         j = i;
//         int per_grp = tab->data;
//         traverse = 0;
//        while (traverse < size)
// 	    {
// 		    if (per_grp < a[j])
// 		    {
// 		    	per_grp = a[j];
// 		    	// tab[i] = true;
//                 count++;
// 		    }
//             // else{
//                 // tab[j] = false;
//             // }
// 		    j++;
// 		    j = j % size;
// 		    traverse++;
// 	    }
//         tab[i] = count;
//         i++;
//     }
//     return (tab);
// }