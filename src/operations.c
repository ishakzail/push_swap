/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:14:43 by izail             #+#    #+#             */
/*   Updated: 2022/02/08 11:11:55 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"


t_stack   *stacklast(t_stack **s)
{
    t_stack   *tmp;
    if (!*s)
        return (NULL);
    tmp = *s;
    while (tmp->link)
        tmp = tmp->link;
    return (tmp);
}

void    push_front(t_stack **s, int data)
{
    t_stack *top;
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
    // free(top);
}

void    push_back(t_stack **s, int data)
{
    t_stack   *tmp;
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

void    pop_back(t_stack **s)
{
    t_stack   *tmp;
    t_stack   *prev;
    
    tmp = *s;
    while (tmp->link)
    {
        prev = tmp;
        tmp = tmp->link;
    }
    free(tmp);
    prev->link = NULL;

}

void    pop_front(t_stack **s)
{
    t_stack *tmp;
    tmp = *s;
    *s = (*s)->link;
    free(tmp);
}

void    ft_swap(t_stack *s)
{
    int tmpvar;

    tmpvar = s->data;
    s->data = s->link->data;
    s->link->data = tmpvar;
}

void    ft_sx(t_stack **stack_1, t_stack **stack_2)
{
    (void)stack_2;
    if (!stack_1 || !*stack_1)
        ft_exit_ps("Stack cannot be swipped", 2);
    else
        ft_swap(*stack_1);
}

// void    ft_ss(t_stack *a, t_stack *b)
// {
//     ft_sx(b,a);
//     ft_sx(a,b);
// }

void    ft_px(t_stack **stack_1, t_stack **stack_2)
{
    if (!stack_1)
        ft_exit_ps("Stack 1 is empty", 2);
    push_front(stack_2,(*stack_1)->data);
    pop_front(stack_1);
}

void    ft_rotate(t_stack **s)
{
    t_stack   *first;
    t_stack   *last;

    first = *s;
    last = *s;

    while (last->link != NULL)
        last = last->link;

    (*s) = first->link;
    first->link = NULL;
    last->link = first;
}

void    ft_rx(t_stack **stack_1, t_stack **stack_2)
{
    (void)stack_2;
    if (!stack_1 || !*stack_1)
        ft_exit_ps("Stack is empty", 2);
    else
        ft_rotate(stack_1);
}

void    ft_rr(t_stack **stack_1, t_stack **stack_2)
{
    ft_rx(stack_1,stack_2);
    ft_rx(stack_2,stack_1);
}

void    reverse(t_stack **s)
{
    t_stack   *tmp;

    tmp = stacklast(s);
    push_front(s,tmp->data);
    pop_back(s);
}

void    ft_rrx(t_stack **stack_1, t_stack **stack_2)
{
    (void)stack_2;
    if (!stack_1 || !*stack_1)
        ft_exit_ps("Stack is empty", 2);
    else
        reverse(stack_1);
}

void ft_rrr(t_stack **stack_1, t_stack **stack_2)
{
    ft_rrx(stack_1,stack_2);
    ft_rrx(stack_2,stack_1);
}


// void	sx(t_stack **stack_1, t_stack **stack_2)
// {
// 	t_stack	*tmp;

// 	(void)stack_2;
// 	if (ft_stacksize(stack_1) >= 2)
// 	{
// 		tmp = (*stack_1)->link;
// 		(*stack_1)->link = tmp->link;
// 		push_front(stack_1, tmp->data);
// 	}
// }

// void	px(t_stack **stack_1, t_stack **stack_2)
// {
// 	t_stack	*tmp;

// 	if (ft_stacksize(stack_1))
// 	{
// 		tmp = *stack_1;
// 		*stack_1 = (*stack_1)->link;
// 		push_front(stack_2, tmp->data);
// 	}
// }

// void	rx(t_stack **stack_1, t_stack **stack_2)
// {
// 	t_stack	*tmp;

// 	(void)stack_2;
// 	if (ft_stacksize(stack_1) >= 2)
// 	{
// 		tmp = *stack_1;
// 		*stack_1 = (*stack_1)->link;
// 		tmp->link = 0;
// 		push_front(stack_1, tmp->data);
// 	}
// }

// void	rrx(t_stack **stack_1, t_stack **stack_2)
// {
// 	t_stack	*last;
// 	t_stack	*tmp;

// 	(void)stack_2;
// 	if (ft_stacksize(stack_1) >= 2)
// 	{
// 		last = *stack_1;
// 		while (last->link)
// 		{
// 			tmp = last;
// 			last = last->link;
// 		}
// 		tmp->link = 0;
// 		last->link = *stack_1;
// 		*stack_1 = last;
// 	}
// }

void	run(char *cmd, t_stack **stack_1, t_stack **stack_2, int x)
{
	int			tmp;
	void		(*f)(t_stack **, t_stack **);
	const int	len = ft_strlen(cmd);

	tmp = abs(x);
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sb", len)
		|| !ft_strncmp(cmd, "ss", len))
		f = &ft_sx;
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pb", len))
		f = &ft_px;
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "rb", len)
		|| !ft_strncmp(cmd, "rr", len))
		f = &ft_rx;
	else
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