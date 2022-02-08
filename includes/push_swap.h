/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:16:06 by izail             #+#    #+#             */
/*   Updated: 2022/02/08 11:12:30 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "libft/libft.h"

typedef struct stack
{
    int     data;
    struct  stack* link;
}t_stack;

t_stack    *ft_stacknew(int data);

t_stack *pop(t_stack **s);
t_stack *push(t_stack **s, int data);

void    ft_swap(t_stack *a);
void    ft_sa(t_stack *s);
void    ft_sb(t_stack *b);
void    ft_ss(t_stack *a, t_stack *b);
void    ft_pa(t_stack **a, t_stack **b);
void    ft_pb(t_stack **a, t_stack **b);
void    ft_rotate(t_stack **s);
void    ft_ra(t_stack **a);
void    ft_rb(t_stack **b);
void    ft_rr(t_stack **a,t_stack **b);
t_stack   *stacklast(t_stack **s);
void    reverse(t_stack **s);
void    pop_back(t_stack **s);
void    pop_front(t_stack **s);
void    push_back(t_stack **s, int data);
void    push_front(t_stack **s, int data);
void    ft_rra(t_stack **a);
void    ft_rrb(t_stack **b);
void    ft_rrr(t_stack **a, t_stack **b);


/*************** Checks ***************/

void check_dup(char **av);

t_stack    *fill_list(int ac, char **input);

void ft_exit_ps(char *arg, int err);

int split_args(char ***strs, char **av, char *sep);

long    ft_atol(char *str);
int    check_if_int(char *str);

void printStack(t_stack **s);
