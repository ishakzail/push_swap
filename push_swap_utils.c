/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:14:43 by izail             #+#    #+#             */
/*   Updated: 2022/01/13 17:14:44 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

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
        printf("stack cannot be swipped !");
        exit(1);
    }
    else
        ft_swap(a);
}

void    ft_sb(stack *b)
{

    if (!b || b->link == NULL)
    {
        printf("stack cannot be swipped !");
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

void    ft_pa(stack *a, stack *b)
{
    
}