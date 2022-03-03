/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:37:41 by izail             #+#    #+#             */
/*   Updated: 2022/02/12 12:37:43 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_min(t_stack *stack)
{
	int		min;
	int		num;

	min = stack->data;
	while (stack)
	{
		num = stack->data;
		if (min > num)
			min = num;
		stack = stack->link;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	int		max;
	int		num;

	max = stack->data;
	while (stack)
	{
		num = stack->data;
		if (max < num)
			max = num;
		stack = stack->link;
	}
	return (max);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		ft_find_smallest_index(t_stack *stack_a)
{
	int	idx;
	int min_nbr;

	idx = 0;
	min_nbr = stack_min(stack_a);
	while (stack_a)
	{
		if (stack_a->data == min_nbr)
			return (idx);
		else 
			idx++;
		stack_a = stack_a->link;
	}
	return (idx);
}

// int	*ft_stack_get_frame_content_by_index(t_stack *stack, int index)
// {
// 	t_stack	*iter;
// 	int				i;

// 	if (index < 0 || stack == NULL || ft_stacksize(stack) == 0)
// 		return (NULL);
// 	iter = stack->link;
// 	i = 0;
// 	while (i < index && iter != NULL)
// 	{
// 		iter = iter->link;
// 		++i;
// 	}
// 	if (iter == NULL)
// 		return (NULL);
// 	return (&iter->data);
// }

void	ft_place_smallest_first(t_stack **stack_a, t_stack **stack_b)
{
	int		small_index;
	
	stack_b = 0;
	small_index = ft_find_smallest_index(*stack_a);
	if (small_index == 0)
		return ;
	while (small_index)
	{
		if (small_index <=  ft_stacksize(*stack_a)/ 2)
			ft_run(&ft_ra, stack_a, stack_b);
		else
			ft_run(&ft_rra, stack_a, stack_b);
		small_index--;
	}
	
}