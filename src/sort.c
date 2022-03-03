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
	
	const int	num_1 = (*stack_a)->data;
	const int	num_2 = (*stack_a)->link->data;
	const int	num_3 = (*stack_a)->link->link->data;

    
	if (num_1 == stack_min(*stack_a) && num_2 == stack_max(*stack_a))
	{
		ft_run(&ft_sa, stack_a, stack_b);
		ft_run(&ft_ra, stack_a, stack_b);
	}
	else if (num_2 == stack_min(*stack_a) && num_3 == stack_max(*stack_a))
		ft_run(&ft_sa, stack_a, stack_b);
	else if (num_3 == stack_min(*stack_a) && num_2 == stack_max(*stack_a))
		ft_run(&ft_rra, stack_a, stack_b);
	else if (num_2 == stack_min(*stack_a) && num_1 == stack_max(*stack_a))
		ft_run(&ft_ra, stack_a, stack_b);
	else
	{
		ft_run(&ft_sa, stack_a, stack_b);
		ft_run(&ft_rra, stack_a, stack_b);
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	ft_place_smallest_first(stack_a,stack_b);
	ft_run(&ft_pb,stack_a, stack_b);
	ft_place_smallest_first(stack_a,stack_b);
	ft_run(&ft_pb,stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort_3(stack_a,stack_b);
	ft_run (&ft_pa,stack_a, stack_b);
	ft_run (&ft_pa,stack_a, stack_b);
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