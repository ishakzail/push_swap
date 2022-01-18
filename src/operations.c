/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:14:43 by izail             #+#    #+#             */
/*   Updated: 2022/01/18 18:06:20 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"


stack   *stacklast(stack **s)
{
    stack   *tmp;
    if (!*s)
        return (NULL);
    tmp = *s;
    while (tmp->link)
        tmp = tmp->link;
    return (tmp);
}

void    push_front(stack **s, int data)
{
    stack *top;
    top = (stack *)malloc(sizeof(*top));
    if (!top)
    {
        printf("Stack overflow !");
        exit(1);
    }
    top->data = data;
    top->link = NULL;
    top->link = *s;
    *s = top;
    //free(top);
}

void    push_back(stack **s, int data)
{
    stack   *tmp;
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

void    pop_back(stack **s)
{
    stack   *tmp;
    stack   *prev;
    
    tmp = *s;
    while (tmp->link)
    {
        prev = tmp;
        tmp = tmp->link;
    }
    free(tmp);
    prev->link = NULL;

}

void    pop_front(stack **s)
{
    stack *tmp;
    tmp = *s;
    *s = (*s)->link;
    free(tmp);
}

void    ft_swap(stack *s)
{
    int tmpvar;

    tmpvar = s->data;
    s->data = s->link->data;
    s->link->data = tmpvar;
}

void    ft_sa(stack *a)
{

    if (!a || a->link == NULL)
    {
        printf("stack a cannot be swipped !");
        exit(1);
    }
    else
        ft_swap(a);
}

void    ft_sb(stack *b)
{

    if (!b || b->link == NULL)
    {
        printf("stack b cannot be swipped !");
        exit(1);
    }
    else
        ft_swap(b);
}

void    ft_ss(stack *a, stack *b)
{
    ft_sb(b);
    ft_sa(a);
}

void    ft_pa(stack **a, stack **b)
{
    if (!b)
    {
         printf("b is empty");
        exit(1);
    }
    push_front(a,(*b)->data);
    pop_front(b);
}

void    ft_pb(stack **a, stack **b)
{
    if (!b)
    {
         printf("b is empty");
        exit(1);
    }
    push_front(b,(*a)->data);
    pop_front(a);
}

void    ft_rotate(stack **s)
{
    stack   *first;
    stack   *last;

    first = *s;
    last = *s;

    while (last->link != NULL)
        last = last->link;

    (*s) = first->link;
    first->link = NULL;
    last->link = first;
}

void    ft_ra(stack **a)
{
    if (!a || !*a)
    {
        printf("stack is empty");
        exit(1);
    }
    else
        ft_rotate(a);
}

void    ft_rb(stack **b)
{
    if (!b || !*b)
    {
        printf("stack is empty");
        exit(1);
    }
    else
        ft_rotate(b);
}

void    ft_rr(stack **a, stack **b)
{
    ft_ra(a);
    ft_rb(b);
}

void    reverse(stack **s)
{
    stack   *tmp;

    tmp = stacklast(s);
    push_front(s,tmp->data);
    pop_back(s);
}

void    ft_rra(stack **a)
{
    if (!a || !*a)
    {
        printf("stack is empty");
        exit(1);
    }
    else
        reverse(a);
}

void    ft_rrb(stack **b)
{
    if (!b || !*b)
    {
        printf("stack is empty");
        exit(1);
    }
    else
        reverse(b);
}

void ft_rrr(stack **a, stack **b)
{
    ft_rra(a);
    ft_rrb(b);
}
