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

void    ft_swap(t_stack **s)
{
    int tmpvar;

    tmpvar = (*s)->data;
    (*s)->data = (*s)->link->data;
    (*s)->link->data = tmpvar;
}

void    ft_sa(t_stack **a)
{

    if (!a || (*a)->link == NULL)
    {
        printf("t_stack a cannot be swipped !");
        exit(1);
    }
    else
        ft_swap(a);
}

void    ft_sb(t_stack **b)
{

    if (!b || (*b)->link == NULL)
    {
        printf("t_stack b cannot be swipped !");
        exit(1);
    }
    else
        ft_swap(b);
}

void    ft_ss(t_stack **a, t_stack **b)
{
    ft_sb(b);
    ft_sa(a);
}

void    ft_pa(t_stack **a, t_stack **b)
{
    if (!b)
    {
        printf("b is empty");
        exit(1);
    }
    push_front(a,(*b)->data);
    pop_front(b);
}

void    ft_pb(t_stack **a, t_stack **b)
{
    if (!b)
    {    
         printf("b is empty");
        exit(1);
    }
    push_front(b,(*a)->data);
    pop_front(a);
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

void    ft_ra(t_stack **a)
{
    if (!a || !*a)
    {
        printf("t_stack is empty");
        exit(1);
    }
    else
        ft_rotate(a);
}

void    ft_rb(t_stack **b)
{
    if (!b || !*b)
    {
        printf("t_stack is empty");
        exit(1);
    }
    else
        ft_rotate(b);
}

void    ft_rr(t_stack **a, t_stack **b)
{
    ft_ra(a);
    ft_rb(b);
}

void    reverse(t_stack **s)
{
    t_stack   *tmp;

    tmp = stacklast(s);
    push_front(s,tmp->data);
    pop_back(s);
}

void    ft_rra(t_stack **a)
{
    if (!a || !*a)
    {
        printf("t_stack is empty");
        exit(1);
    }
    else
        reverse(a);
}

void    ft_rrb(t_stack **b)
{
    if (!b || !*b)
    {
        printf("t_stack is empty");
        exit(1);
    }
    else
        reverse(b);
}

void ft_rrr(t_stack **a, t_stack **b)
{
    ft_rra(a);
    ft_rrb(b);
}

void    ft_print_op_name(t_op_name operation)
{
    if (operation == &ft_sa)
        write(1, "sa\n",4);
	else if (operation == &ft_sb)
		write(1, "sb\n",4);
	else if (operation == &ft_ss)
		write(1, "ss\n",4);
	else if (operation == &ft_pa)
		write(1, "pa\n",4);
	else if (operation == &ft_pb)
		write(1, "pb\n",4);
	else if (operation == &ft_ra)
		write(1, "ra\n",4);
	else if (operation == &ft_rb)
		write(1, "rb\n",4);
	else if (operation == &ft_rr)
		write(1, "rr\n",4);
	else if (operation == &ft_rra)
		write(1, "rra\n",5);
	else if (operation == &ft_rrb)
		write(1, "rrb\n",5);
	else if (operation == &ft_rrr)
		write(1, "rrr\n",5);
	else
		ft_putendl_fd("Error. Unknown push_swap operation", STDERR_FILENO);
}


void    ft_run(t_op_name operation, t_stack **stack_a, t_stack **stack_b)
{
    if (operation == NULL || stack_a == NULL || stack_b == NULL)
        return ;
    if (operation == &ft_sa || operation == &ft_ra || operation == &ft_rra)
		operation(stack_a);
	else if (operation == &ft_sb || operation == &ft_rb || operation == &ft_rrb)
		operation(stack_b);
	else if (operation == &ft_ss || operation == &ft_rr || operation == &ft_rrr)
		operation(stack_a, stack_b);
	else if (operation == &ft_pa || operation == &ft_pb)
		operation(&stack_a, &stack_b);
	ft_print_op_name(operation);
}
