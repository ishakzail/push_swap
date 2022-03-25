/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:14:43 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 16:44:44 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sx(t_stack **stack_1, t_stack **stack_2)
{
	(void)stack_2;
	if (!stack_1 || !*stack_1)
		ft_exit_ps("Stack cannot be swipped", 2);
	else
		ft_swap(*stack_1);
}

void	ft_px(t_stack **stack_1, t_stack **stack_2)
{
	if (!stack_1)
		ft_exit_ps("Stack is empty", 2);
	push_front(stack_2, (*stack_1)->data);
	pop_front(stack_1);
}

void	ft_rx(t_stack **stack_1, t_stack **stack_2)
{
	(void)stack_2;
	if (!stack_1 || !*stack_1)
		ft_exit_ps("Stack is empty", 2);
	else
		ft_rotate(stack_1);
}

void	ft_rrx(t_stack **stack_1, t_stack **stack_2)
{
	(void)stack_2;
	if (!stack_1 || !*stack_1)
		ft_exit_ps("Stack is empty", 2);
	else
		reverse(stack_1);
}

void	ft_run(char *cmd, t_stack **stack_1, t_stack **stack_2, int x)
{
	int			tmp;
	void		(*f)(t_stack **, t_stack **);
	const int	len = ft_strlen(cmd);

	tmp = ft_abs(x);
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sb", len)
		|| !ft_strncmp(cmd, "ss", len))
		f = &ft_sx;
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pb", len))
		f = &ft_px;
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "rb", len)
		|| !ft_strncmp(cmd, "rr", len))
		f = &ft_rx;
	else if (!ft_strncmp(cmd, "rra", len) || !ft_strncmp(cmd, "rrb", len)
		|| !ft_strncmp(cmd, "rrr", len))
		f = &ft_rrx;
	while (tmp--)
	{
		f(stack_1, stack_2);
		if (stack_2 && f != ft_px)
			f(stack_2, 0);
		if (x > 0)
			ft_putendl_fd(cmd, 1);
	}
}
