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

    t_stack *a;
    t_stack *b;
    int *tmp;
    tmp = 0;
    b = 0;
    char    **strs;
    int     i;

    if (ac < 2)
        ft_exit_ps("Wrong number of arguments", 1);
    strs = 0;
    i = split_args(&strs,av + 1," ");
    a = fill_list(i,strs);
    // printf("i == %d\n",i);
    // while(i)
    // {
    //     printf("i == %d || strs == %s\n",i, strs[i]);
    //     i--;
    // }
    check_dup(strs);
    sort(&a);
    // ft_rrx(&a, &b);
    // ft_rx(&a, &b);
    // ft_px(&b, &a);
    // tmp = put_stack_in_arr(a);
    // int size = ft_stacksize(a);
    // ft_lis(tmp, size);
    // printf("biggest index == %d\n",ft_find_biggest_index(a));
    // sort_arr(tmp, size);
    // insertion_sort(tmp,size);
    // printf("lis == %d\n",lis(tmp, size));
    // int j = 0;
    // while (tmp[j] != '\0')
    // {
    //     printf("tmp == %d\n",tmp[j]);
    //     j++;
    // }
    // printf("tmp == %d",tmp[2]);
    // sort_stack(tmp);
    // set_groups();
    // if (!is_sorted(&a))
    // sort(&a, &b);
    // sort_bigg(&a, &b);
    // sort_stack(&a);
    // while (i--)
    //     printf("i == %d || strs == %s\n",i, strs[i]);
    // sort_100(&a,&b);
    // ft_run(&ft_pb, &a, &b);
    // ft_place_smallest_first(&a,&b);
    //ft_sx(a);
    // printStack(&a);
    //sort_3(&a,&b);
    //ft_px(b,a);
    // if (is_sorted(a) == 0)
    //     printf("stack not sorted !\n");
    // else 
    //      printf("stack a is sorted !\n");
    // is_sorted(&a) ? printf("==== YES ====\n") : printf(" ==== NO ====\n");
    // printf("arg1 == %d\n",ft_atoi(strs[0]));
    // ft_rrx(&a,&b);
    // sort_bigg(&a,&b);
    // sort(&a, &b);
    // printf("stack idx mid == %d\n",stack_idx_mid(a, ft_stacksize(a)));
    // printStack(&a);
    // printStack(&b);
    // sleep(300);
    return (0);
}