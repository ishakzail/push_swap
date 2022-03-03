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

    t_stack *b;
    char    **strs;
    int     i;
    if (ac < 2)
        ft_exit_ps("Wrong number of arguments", 1);
    a = 0;
    b = 0;
    strs = 0;
    i = split_args(&strs,av + 1," ");
    a = fill_list(i,strs);   
    check_dup(strs);

    // ft_sa(&a);
    // ft_ra(&a);
    //sort_3(&a,&b);
    // if (!is_sorted(a))
    //     sort_3(a,b);
    // else 
    //     printf("stack is sorted !");

    // ft_sa(a);
    // ft_ra(a);
    // while(1);
    // sort_stack(&a);
    
    // printf("size == %d\n",ft_stacksize(a));
    // ft_place_smallest_first(&a,&b);

    // sort_5(&a,&b);
    // if(ft_stacksize(a) == 3)
    //     sort_3(&a,&b);
    // else if (ft_stacksize(a) == 5)
    //     sort_5(&a,&b);
    // else 
    //     printf("stack size not handled");

    // printf("s_idx == %d\n",ft_find_smallest_index(a));
    //ft_pb(&a,&b);
    ft_run(&ft_pb,&a, &b);
    printStack(&a);
    printStack(&b);
    //ft_px(b,a);
    // if (is_sorted(a) == 0)
    //     printf("stack not sorted !\n");
    // else 
    //      printf("stack a is sorted !\n");
    // is_sorted(&a) ? printf("==== YES ====\n") : printf(" ==== NO ====\n");
    // printf("arg1 == %d\n",ft_atoi(strs[0]));
    // ft_rrx(&a,&b);
    
    // printStack(&b);
    // free(strs);
    return (0);
}