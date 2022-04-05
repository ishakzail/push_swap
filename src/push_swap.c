/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:22:13 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 22:49:09 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->link;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*tmp;
	char	**strs;
	int		i;

	tmp = 0;
	b = 0;
	if (ac < 2)
		ft_exit_ps("Wrong number of arguments", 1);
	strs = 0;
	i = split_args(&strs, av + 1, " ");
	a = fill_list(i, strs);
	check_dup(strs);
	if (!i)
	{
		ps_free(strs);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (!is_sorted(a))
		sort(&a);
	ft_stackclear(&a);
	ps_free(strs);
	return (0);
}
