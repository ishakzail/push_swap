/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:22:13 by izail             #+#    #+#             */
/*   Updated: 2022/02/08 11:11:41 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int ac, char **av)
{

    t_stack *a , *b;
    char    **strs;
    int     i;
    int     var;

    if (ac < 2)
        ft_exit_ps("Wrong number of arguments", 1);
    strs = 0;
    i = split_args(&strs,av + 1," ");
    printf("number of args == %d\n",i);
    a = fill_list(i,strs);
    check_dup(strs);
    printStack(&a);
    if (is_sorted(a) == 0)
        printf("stack not sorted !\n");
    else 
       printf("stack a is sorted !\n");

    
    return (0);
}
