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

typedef void    (*t_operation)();

typedef struct stack
{
    int     data;
    struct  stack* link;
}t_stack;

t_stack    *ft_stacknew(int data);

t_stack *pop(t_stack **s);
t_stack *push(t_stack **s, int data);
t_stack *stacklast(t_stack **s);

void    pop_back(t_stack **s);
void    pop_front(t_stack **s);
void    push_back(t_stack **s, int data);
void    push_front(t_stack **s, int data);

// void    ft_swap(t_stack *s);
// // void    ft_sx(t_stack *s);
// void    ft_sx(t_stack **stack_1, t_stack **stack_2);
// // void    ft_ss(t_stack *a, t_stack *b);
// void    ft_px(t_stack **stack_1, t_stack **stack_2);
// // void    ft_rotate(t_stack **s);
// // void    ft_rx(t_stack **stack_1);
// void    ft_rx(t_stack **stack_1, t_stack **stack_2);
// // void    ft_rr(t_stack **stack_1, t_stack **stack_2);
// // void    reverse(t_stack **s);
// // void    ft_rrx(t_stack **stack_1);
// void    ft_rrx(t_stack **stack_1, t_stack **stack_2);
// void    ft_rrr(t_stack **stack_1, t_stack **stack_2);


void    ft_sa(t_stack **stack_1, t_stack **stack_2);
void    ft_sb(t_stack **stack_1, t_stack **stack_2);
void    ft_ss(t_stack **a, t_stack **b);
void    ft_pa(t_stack **stack_1, t_stack **stack_2);
void    ft_pb(t_stack **stack_1, t_stack **stack_2);
void    ft_rotate(t_stack **s);
void    ft_ra(t_stack **stack_1, t_stack **stack_2);
void    ft_rb(t_stack **stack_1, t_stack **stack_2);
void    ft_rr(t_stack **stack_1, t_stack **stack_2);
void    reverse(t_stack **s);
void    ft_rra(t_stack **stack_1, t_stack **stack_2);
void    ft_rrb(t_stack **stack_1, t_stack **stack_2);
void    ft_rrr(t_stack **stack_1, t_stack **stack_2);


/*************** Checks ***************/

void        check_dup(char **av);

t_stack    *fill_list(int ac, char **input);

void        ft_exit_ps(char *arg, int err);

int         split_args(char ***strs, char **av, char *sep);

int         ft_abs(int  n);
long        ft_atol(char *str);
int         check_if_int(char *str);

void        printStack(t_stack **s);

int         is_sorted(t_stack **s);

void	    sort_3(t_stack **stack_a, t_stack **stack_b);
void	    sort_4(t_stack **stack_a, t_stack **stack_b);
void	    sort_5(t_stack **stack_a, t_stack **stack_b);
void	    sort_100(t_stack **stack_a, t_stack **stack_b);

int         ft_stacksize(t_stack *stack);

int	        stack_min(t_stack *stack);
int	        stack_max(t_stack *stack);
int	        min(int a, int b);



void    ft_run(t_operation op, t_stack **stack_a, t_stack **stack_b);

void	ft_place_smallest_first(t_stack **stack_a, t_stack **stack_b);
int		ft_find_smallest_index(t_stack *stack_a);

void    sort_stack(t_stack *s);
int	    *put_stack_in_arr(t_stack *stack_a);

void	sort_arr(int *arr, int size);

// void	ft_lis(int *arr, int size);

int		ft_find_biggest_index(t_stack *stack_a);
void	ft_place_biggest_first(t_stack **stack_a, t_stack **stack_b);

void	insertion_sort(int *arr, int size);
// int	    longestSubSeq(int *arr, int size);

int lis(int *arr, int n);
void	ft_rotate_same(t_stack **stack_a, t_stack **stack_b);