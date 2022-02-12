/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:18 by izail             #+#    #+#             */
/*   Updated: 2022/02/08 11:11:22 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack)
{

	const int	num_1 = (*stack)->data;
	const int	num_2 = (*stack)->link->data;
	const int	num_3 = (*stack)->link->link->data;

    if(is_sorted(stack))
        ft_exit_ps("stack already sorted",2);
	if (num_1 == stack_min(*stack) && num_2 == stack_max(*stack))
	{
		run("sa", stack, 0, 1);
		run("ra", stack, 0, 1);
	}
	else if (num_2 == stack_min(*stack) && num_3 == stack_max(*stack))
		run("sa", stack, 0, 1);
	else if (num_3 == stack_min(*stack) && num_2 == stack_max(*stack))
		run("rra", stack, 0, 1);
	else if (num_2 == stack_min(*stack) && num_1 == stack_max(*stack))
		run("ra", stack, 0, 1);
	else
	{
		run("sa", stack, 0, 1);
		run("rra", stack, 0, 1);
	}
}

void	sort_big(t_stack **stack_a)
{
	int		a;
	int		b;
	t_stack	*stack_b;

	stack_b = 0;
	while (ft_stacksize(*stack_a) > 3)
		run("pb", stack_a, &stack_b, 1);
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	while (ft_stacksize(stack_b))
	{
		a = 0;
		b = 0;
		get_min_rotate(*stack_a, stack_b, &a, &b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			rotate_same(stack_a, &stack_b, a, b);
		else
			rotate_diff(stack_a, &stack_b, a, b);
		run("pa", &stack_b, stack_a, 1);
	}
}

// void	sort_final(t_stack **stack)
// {
// 	const int	i = stack_idx_minmax(*stack, stack_min(*stack));

// 	if (i < 0)
// 		run("rra", stack, 0, -i);
// 	else
// 		run("ra", stack, 0, i);
// }

// void	sort(t_stack **stack)
// {
// 	if (ft_lstsize(*stack) == 2)
// 		run("sa", stack, 0, 1);
// 	else if (ft_lstsize(*stack) == 3)
// 		sort_3(stack);
// 	else
// 		sort_big(stack);
// 	sort_final(stack);
// }


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