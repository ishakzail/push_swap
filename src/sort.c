/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:18 by izail             #+#    #+#             */
/*   Updated: 2022/02/08 11:11:22 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_stack **s)
{
    t_stack *node;
    t_stack *tmp;
    int     var;

    tmp = NULL;
    node = *s;
    while (node != NULL)
    {
        tmp = node;
        while (tmp->link != NULL)
        {
            if (tmp->data > tmp->link->data)
            {
                var = tmp->data;
                tmp->data = tmp->link->data;
                tmp->link->data = var;
            }
            tmp = tmp->link;
        }
        node = node->link;
    } 

}

int     is_sorted(t_stack **s)
{
    while ((*s)->link != NULL)
    {
        if (ft_atoi((*s)->data) > ft_atoi((*s)->link->data))
            return (0);
        (*s) = (*s)->link;
    }
    return (1);
}
// t_stack *sort_small(t_stack **stack)
// {
    
// }
