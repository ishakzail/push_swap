/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:16:06 by izail             #+#    #+#             */
/*   Updated: 2022/01/13 17:16:07 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int     data;
    struct  Stack* link;
}stack;

stack *pop(stack **s);
stack *push(stack **s, int data);

void    ft_swap(stack *a);
void    ft_sa(stack *s);
void    ft_sb(stack *b);
void    ft_ss(stack *a, stack *b);
void    ft_pa(stack **a, stack **b);
void    ft_pb(stack **a, stack **b);
void    ft_rotate(stack **s);
void    ft_ra(stack **a);
void    ft_rb(stack **b);
void    ft_rr(stack **a,stack **b);