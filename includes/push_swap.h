/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:16:06 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 22:49:52 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include"libft/libft.h"

typedef struct stack
{
	int				data;
	struct stack	*link;
}t_stack;

t_stack	*ft_stacknew(int data);
t_stack	*pop(t_stack **s);
t_stack	*push(t_stack **s, int data);
t_stack	*stacklast(t_stack **s);
void	pop_back(t_stack **s);
void	pop_front(t_stack **s);
void	push_back(t_stack **s, int data);
void	push_front(t_stack **s, int data);
void	reverse(t_stack **s);
void	ft_rotate(t_stack **s);
void	ft_swap(t_stack *s);
void	ft_sx(t_stack **stack_1, t_stack **stack_2);
void	ft_px(t_stack **stack_1, t_stack **stack_2);
void	ft_rx(t_stack **stack_1, t_stack **stack_2);
void	ft_rrx(t_stack **stack_1, t_stack **stack_2);

void	check_dup(char **av);
t_stack	*fill_list(int ac, char **input);
void	ft_exit_ps(char *arg, int err);
int		split_args(char ***strs, char **av, char *sep);
int		ft_abs(int n);
long	ft_atol(char *str);
int		check_if_int(char *str);

int		is_sorted(t_stack *s);
int		ft_stacksize(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		min(int a, int b);
void	ft_run(char *str, t_stack **stack_1, t_stack **stack_2, int x);

void	sort(t_stack **stack);

int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		min(int a, int b);

int		stack_idx_minmax(t_stack *stack, int num);
void	get_min_rotate(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
void	rotate_same(t_stack **stack_a, t_stack **stack_b, int a, int b);
void	rotate_diff(t_stack **stack_a, t_stack **stack_b, int a, int b);

void	ps_free(char **strs);
void	ft_stackclear(t_stack **stack);
char	*get_next_line(char **str);

#endif
