/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:37:27 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 22:50:31 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_idx_mid(t_stack *stack, int num)
{
	int			current;
	int			next;
	int			ret;
	const int	size = ft_stacksize(stack);

	ret = 1;
	while (stack->link)
	{
		current = (stack->data);
		next = (stack->link->data);
		if (num > current && num < next)
			break ;
		++ret;
		stack = stack->link;
	}
	if (ret == size)
		ret = 0;
	else if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

int	stack_idx_minmax(t_stack *stack, int num)
{
	int			ret;
	int			x;
	const int	size = ft_stacksize(stack);

	ret = 0;
	x = stack_max(stack);
	if (num <= stack_min(stack))
		x = stack_min(stack);
	else
		++ret;
	while (stack)
	{
		if ((stack->data) == x)
			break ;
		++ret;
		stack = stack->link;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

void	get_min_rotate(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	int			i;
	int			j;
	int			num;
	int			x;
	const int	size_b = ft_stacksize(stack_b);

	x = -1;
	while (stack_b && ++x >= 0)
	{
		num = (stack_b->data);
		if (num < stack_min(stack_a) || num > stack_max(stack_a))
			i = stack_idx_minmax(stack_a, num);
		else
			i = stack_idx_mid(stack_a, num);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || ft_abs(*a) + ft_abs(*b) > ft_abs(i) + ft_abs(j))
		{
			*a = i;
			*b = j;
		}
		stack_b = stack_b->link;
	}
}

void	rotate_same(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		ft_run("rr", stack_a, stack_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			ft_run("rb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_run("ra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
	else
	{
		ft_run("rrr", stack_a, stack_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			ft_run("rrb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_run("rra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
}

void	rotate_diff(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	if (a >= 0 && b < 0)
	{
		ft_run("ra", stack_a, 0, a);
		ft_run("rrb", stack_b, 0, ft_abs(min(a, b)));
	}
	else
	{
		ft_run("rb", stack_b, 0, b);
		ft_run("rra", stack_a, 0, ft_abs(min(a, b)));
	}
}
