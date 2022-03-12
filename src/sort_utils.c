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

// int	stack_next_max(t_stack *stack)
// {
// 	int	next_max;
// 	int	prev_max;
// 	int num;

// 	prev_max = stack_max(stack);
// 	num = stack->data;
// 	if (prev_max == stack->data)
// 		num = stack->data;
// 	while (stack)
// 	{
// 		if (prev_max < num)
// 			prev_max = num		
// 	}
// }
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

int		ft_find_biggest_index(t_stack *stack_a)
{
	int	idx;
	int max_nbr;

	idx = 0;
	max_nbr = stack_max(stack_a);
	while (stack_a)
	{
		if (stack_a->data == max_nbr)
			return (idx);
		else 
			idx++;
		stack_a = stack_a->link;
	}
	return (idx);
}

void	ft_place_smallest_first(t_stack **stack_a, t_stack **stack_b)
{	
	stack_b = 0;
	
	if (ft_find_smallest_index(*stack_a) == 0)
		return ;
	while (ft_find_smallest_index(*stack_a) != 0)
	{
		if (ft_find_smallest_index(*stack_a) <=  ft_stacksize(*stack_a) / 2)
			ft_run(&ft_ra, stack_a, stack_b);
		else if (ft_find_smallest_index(*stack_a) > ft_stacksize(*stack_a) / 2)
			ft_run(&ft_rra, stack_a, stack_b);
	}
}

void	ft_place_biggest_first(t_stack **stack_a, t_stack **stack_b)
{	
	stack_b = 0;
	
	if (ft_find_biggest_index(*stack_b) == 0)
		return ;
	while (ft_find_biggest_index(*stack_b) != 0)
	{
		if (ft_find_biggest_index(*stack_b) <=  ft_stacksize(*stack_b) / 2)
			ft_run(&ft_ra, stack_a, stack_b);
		else if (ft_find_biggest_index(*stack_b) > ft_stacksize(*stack_b) / 2)
			ft_run(&ft_rra, stack_a, stack_b);
	}
}

void	ft_rotate_same(t_stack **stack_a, t_stack **stack_b)
{
	stack_b = 0;
	if (ft_find_biggest_index(*stack_b) == 0 && ft_find_smallest_index(*stack_a))
		return ;
	while ((ft_find_biggest_index(*stack_b) !=0) && (ft_find_smallest_index(*stack_a) != 0))
	{
		if ((ft_find_smallest_index(*stack_a) <= ft_stacksize(*stack_a) / 2) &&
			ft_find_biggest_index(*stack_b) <=  ft_stacksize(*stack_b) / 2)
			ft_run(&ft_rr, stack_a, stack_b);
		else if ((ft_find_biggest_index(*stack_b) > ft_stacksize(*stack_b) / 2) &&
				(ft_find_smallest_index(*stack_a) > ft_stacksize(*stack_a) / 2))
			ft_run(&ft_rra, stack_a, stack_b);
	}
}

// void	ft_rotate_diff(t_stack **stack_a, t_stack **stack_b)
// {
// 	stack_b = 0;
// 	if (ft_find_smallest_index(stack_a) == 0)
// 		return ;
// 	while ((ft_find_smallest_index))
// }