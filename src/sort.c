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
#include <limits.h>
void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	int	num_2;
	int	num_3;

	stack_b = 0;
	if (stack_a == NULL)
		return ;
	ft_place_smallest_first(stack_a, stack_b);
	num_2 = (*stack_a)->link->data;
	num_3 = (*stack_a)->link->link->data;
	if (num_2 > num_3)
		ft_run(&ft_sa, stack_a, stack_b);
	ft_place_smallest_first(stack_a, stack_b);
}

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

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	// printf("size == %d\n", ft_stacksize(*stack_a));
	while (ft_stacksize(*stack_a))
	{
		ft_place_smallest_first(stack_a, stack_b);
		ft_run(&ft_pb, stack_a, stack_b);
	}
	while (ft_stacksize(*stack_b))
		ft_run(&ft_pa, stack_a, stack_b);
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