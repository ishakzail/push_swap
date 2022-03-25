/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:27:57 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 20:42:04 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stacklast(t_stack **s)
{
	t_stack	*tmp;

	if (!*s)
		return (NULL);
	tmp = *s;
	while (tmp->link)
		tmp = tmp->link;
	return (tmp);
}

void	push_front(t_stack **s, int data)
{
	t_stack	*top;

	top = (t_stack *)malloc(sizeof(*top));
	if (!top)
	{
		printf("t_stack overflow !");
		exit(1);
	}
	top->data = data;
	top->link = NULL;
	top->link = *s;
	*s = top;
}

void	push_back(t_stack **s, int data)
{
	t_stack	*tmp;

	if (!s)
		return ;
	if (*s)
	{
		tmp = stacklast(s);
		tmp->data = data;
		tmp->link = *s;
	}
	else
		tmp = *s;
}

void	pop_back(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *s;
	while (tmp->link)
	{
		prev = tmp;
		tmp = tmp->link;
	}
	free(tmp);
	prev->link = NULL;
}

void	pop_front(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	*s = (*s)->link;
	free(tmp);
}
