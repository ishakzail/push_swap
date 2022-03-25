/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:10:58 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 18:21:11 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int data)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->link = NULL;
	return (tmp);
}

int	ft_stacksize(t_stack *s)
{
	int	ret;

	ret = 0;
	while (s)
	{
		s = s->link;
		ret++;
	}
	return (ret);
}

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

int	ft_abs(int n)
{
	int	abs;

	if (n < 0)
		abs = -1 * n;
	else
		abs = n;
	return (abs);
}

t_stack	*fill_list(int ac, char **input)
{
	int		i;
	t_stack	*s;

	i = ac - 1;
	while (i >= 0)
	{
		if (!check_if_int(input[i]))
			ft_exit_ps("Error\n", 2);
		if (i == (ac - 1))
			s = ft_stacknew(ft_atoi(input[i]));
		else
			push_front(&s, ft_atoi(input[i]));
		i--;
	}
	return (s);
}
