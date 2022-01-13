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

void    ft_swap(stack *a);
void    ft_sa(stack *s);
void    ft_sb(stack *b);
void    ft_ss(stack *a, stack *b);


