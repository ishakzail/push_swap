/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:22:13 by izail             #+#    #+#             */
/*   Updated: 2022/01/18 18:05:39 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int ac, char **av)
{

    t_stack *a , *b;
    char    **strs;
    int     i;
    int     var;

    // printf("res == %d\n",check_if_int("4.5"));
    if (ac < 2)
        ft_exit_ps("Wrong number of arguments", 1);
    strs = 0;
    i = split_args(&strs,av + 1," ");
    a = fill_list(i,strs);
    check_dup(strs);
    printStack(&a);
    return (0);

}
