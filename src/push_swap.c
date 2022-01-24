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

t_stack    *ft_stacknew(int data)
{
    t_stack    *tmp;

    tmp = (t_stack *)malloc(sizeof(*tmp));
    if (!tmp)
        return (NULL);
    tmp->data = data;
    tmp->link = NULL;
    //printf("t_stack created successfully !");
    return (tmp);
}

void printStack(t_stack **s)
{
    if (s == NULL || !*s)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    printf("The stack elements are :");
    while (*s)
    {
        printf("\n%d ", (*s)->data);
        (*s) = (*s)->link;
    }
    printf("\n");
}

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

int main(int ac, char **av)
{

    t_stack *a , *b;
    int i;
    int var;

    if (ac < 2)
    {
        printf("Wrong number of arguments");
        exit(1);
    }
    a = fill_list(ac,av);
    check_dup(av);
    
        
    // push_front(&a, 2);
    // push_front(&a, 3);
    // push_front(&a, 4);
    // push_front(&a, 5);
    // push_front(&a, 6);
    // push_front(&a, 7);
    // push_front(&a, 8);
    // push_front(&b, 2);
    // push_front(&b, 3);
    // push_front(&b, 4);
    // push_front(&b, 5);
   // pop_back(&a);
    // pop_back(&b);
    //ft_ss(a,b);
    // ft_pa(&a,&b);
    // ft_pb(&a,&b);
    // ft_rotate(&a);
    //ft_ra(&a);
    // ft_rr(&a,&b);
    // ft_rrr(&a,&b);
    //ft_rra(&a);
    printStack(&a);
    //printStack(&b);
    return (0);

}
