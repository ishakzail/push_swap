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

    t_stack *a ;
    char    **strs;
    int     i;

    if (ac < 2)
        ft_exit_ps("Wrong number of arguments", 1);
    strs = 0;
    i = split_args(&strs,av + 1," ");
    a = fill_list(i,strs);
    check_dup(strs);
    // sort_3(&a);

    printf("idx == %d\n",stack_idx_mid(a, 7));


    // sort_stack(&a);
    //ft_sx(a);
    // printStack(&a);
    
    //ft_px(b,a);
    // if (is_sorted(a) == 0)
    //     printf("stack not sorted !\n");
    // else 
    //      printf("stack a is sorted !\n");
    // is_sorted(&a) ? printf("==== YES ====\n") : printf(" ==== NO ====\n");
    // printf("arg1 == %d\n",ft_atoi(strs[0]));
    // ft_rrx(&a,&b);
    printStack(&a);
    // printStack(&b);

    return (0);
}