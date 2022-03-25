/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:37:26 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 20:44:45 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *s)
{
	int	tmpvar;

	tmpvar = s->data;
	s->data = s->link->data;
	s->link->data = tmpvar;
}

void	ft_rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	first = *s;
	last = *s;
	while (last->link != NULL)
		last = last->link;
	(*s) = first->link;
	first->link = NULL;
	last->link = first;
}

void	reverse(t_stack **s)
{
	t_stack	*tmp;

	tmp = stacklast(s);
	push_front(s, tmp->data);
	pop_back(s);
}
