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

