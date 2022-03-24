/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:18 by izail             #+#    #+#             */
/*   Updated: 2022/02/12 12:38:00 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static void	sort_3(t_stack **stack)
{
	const int	num_1 = (*stack)->data;
	const int	num_2 = (*stack)->link->data;
	const int	num_3 = (*stack)->link->link->data;

	if (num_1 == stack_min(*stack) && num_2 == stack_max(*stack))
	{
		ft_run("sa", stack, 0, 1);
		ft_run("ra", stack, 0, 1);
	}
	else if (num_2 == stack_min(*stack) && num_3 == stack_max(*stack))
		ft_run("sa", stack, 0, 1);
	else if (num_3 == stack_min(*stack) && num_2 == stack_max(*stack))
		ft_run("rra", stack, 0, 1);
	else if (num_2 == stack_min(*stack) && num_1 == stack_max(*stack))
		ft_run("ra", stack, 0, 1);
	else
	{
		ft_run("sa", stack, 0, 1);
		ft_run("rra", stack, 0, 1);
	}
}

static void	sort_big(t_stack **stack_a)
{
	int		a;
	int		b;
	t_stack	*stack_b;

	stack_b = 0;
	while (ft_stacksize(*stack_a) > 3)
		ft_run("pb", stack_a, &stack_b, 1);
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	while (ft_stacksize(stack_b))
	{
		a = 0;
		b = 0;
		get_min_rotate(*stack_a, stack_b, &a, &b);
		// printf("AFTER ==> a == %d || b == %d\n", a, b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			rotate_same(stack_a, &stack_b, a, b);
		else
			rotate_diff(stack_a, &stack_b, a, b);
		ft_run("pa", &stack_b, stack_a, 1);
	}
}

static void	sort_final(t_stack **stack)
{
	const int	i = stack_idx_minmax(*stack, stack_min(*stack));

	if (i < 0)
		ft_run("rra", stack, 0, -i);
	else
		ft_run("ra", stack, 0, i);
}

void	sort(t_stack **stack)
{
	if (ft_stacksize(*stack) == 2)
		ft_run("sa", stack, 0, 1);
	else if (ft_stacksize(*stack) == 3)
		sort_3(stack);
	else
		sort_big(stack);
	sort_final(stack);
}



// void	sort_3(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	num_1;
// 	int	num_2;
// 	int	num_3;

// 	num_1 = (*stack_a)->data;
// 	num_2 = (*stack_a)->link->data;
// 	num_3 = (*stack_a)->link->link->data;
// 	if (stack_a == NULL)
// 		return ;
// 	if (num_1 > num_2 && num_1 < num_3)
// 		ft_run(&ft_sa,stack_a,stack_b);
// 	else if (num_1 > num_2 && num_2 > num_3)
// 	{
// 		ft_run(&ft_sa, stack_a, stack_b);
// 		ft_run(&ft_rra, stack_a, stack_b);
// 	}
// 	else if (num_1 > num_2 && num_2 < num_3)
// 		ft_run(&ft_ra,stack_a, stack_b);
// 	else if (num_1 < num_2 && num_2 > num_3)
// 	{
// 		ft_run(&ft_sa, stack_a, stack_b);
// 		ft_run(&ft_ra, stack_a, stack_b);
// 	}
// 	else if (num_1 > num_2 && num_2 > num_3)
// 		ft_run(&ft_rra,stack_a, stack_b);
// }


// int	*put_stack_in_arr(t_stack *stack_a)
// {
// 	int	*arr;
// 	int	i;

// 	arr = 0;
// 	i = 0;
// 	arr = (int *)malloc(sizeof(int) * ft_stacksize(stack_a) + 1);
// 	while (stack_a)
// 	{
// 		arr[i] = stack_a->data;
// 		stack_a = stack_a->link;
// 		i++;
// 	}
// 	arr[i] = '\0';
// 	return (arr);
// }

// void	sort_arr(int *arr, int size)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (arr[i] > arr[j])
// 			{
// 				tmp = arr[i];
// 				arr[i] = arr[j];
// 				arr[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
// void	insertion_sort(int *arr, int size)
// {
// 	int step;
// 	int	key;
// 	int	j;

// 	step = 1;
// 	while (step < size)
// 	{
// 		key = arr[step];
// 		j = step - 1;

// 		while (key < arr[j] && j >= 0)
// 		{
// 			arr[j + 1] = arr[j];
// 			j--;
// 		}
// 		arr[j + 1] = key;
// 		step++;
// 	}
// }

// void	ft_lis(int *arr, int size)
// {
// 	int i;
// 	int prev_len;
// 	int len;
// 	int start;
// 	int *c;

// 	c = (int *)malloc(sizeof(int) * (size + 1));
// 	i = 0;
// 	start = 0;
// 	len = 0;
// 	prev_len = 0;
// 	while (arr[i] < size)
// 	{
// 		if (arr[i + 1] > arr[i])
// 		{
// 			len++;
// 			if (len > prev_len)
// 			{
// 				prev_len = len;
// 				start = i + 1 - len;
// 			}
// 		}
// 		else 
// 		{
// 			prev_len = len;
// 			len = 0;
// 		}
// 		i++;
// 	}
// 	i = -1;
// 	while (++i <= prev_len)
// 	{
// 		c[i] = arr[start+i];
// 		printf("c[%d] == %d\n",i, c[i]);
// 	} 
// }

// void	sort_stack(t_stack *s)
// {
//     t_stack *node;
//     t_stack *tmp;
//     int     var;

//     node = s;
// 	tmp = NULL;
// 	while (node != NULL)
// 	{
// 		tmp = node;
// 		while (tmp->link != NULL)
// 		{
// 			if (tmp->data > tmp->link->data)
// 			{
// 				// printf("tmp->link == %d\n", tmp->link->data);
// 				var = tmp->data;
// 				tmp->data = tmp->link->data;
// 				tmp->link->data = var;
// 				// printf("var == %d\n", var);
// 			}
// 			tmp = tmp->link;
// 		}
// 		node = node->link;
// 	}
// }

// void	sort_big(t_stack **stack_a, t_stack **stack_b)
// {

// }

// void	sort_5(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_place_smallest_first(stack_a,stack_b);
// 	ft_run(&ft_pb,stack_a, stack_b);
// 	ft_place_smallest_first(stack_a,stack_b);
// 	ft_run(&ft_pb,stack_a, stack_b);
// 	sort_3(stack_a,stack_b);
// 	ft_run (&ft_pa,stack_a, stack_b);
// 	ft_run (&ft_pa,stack_a, stack_b);
// }

// void	sort_4(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_place_smallest_first(stack_a,stack_b);
// 	ft_run(&ft_pb,stack_a, stack_b);
// 	sort_3(stack_a,stack_b);
// 	ft_run (&ft_pa,stack_a, stack_b);
// }


// void	sort_bigg(t_stack **a, t_stack **b)
// {
// 	int a_size;

// 	a_size = ft_stacksize(*a);
// 	while (ft_stacksize(*a) > a_size / 2)
// 		ft_run(&ft_pb, a, b);
// 	while (ft_stacksize(*b))
// 	{	
// 		ft_place_biggest_first(a, b);
// 		// // ft_place_smallest_first(a, b);
// 		// ft_run(&ft_pa, a , b);
// 	}
// 	//while(ft_stacksize(*b))
		
// }
// void	sort_100(t_stack **stack_a, t_stack **stack_b)
// {
	
// 	int		a;
// 	int		b;

// 	while (ft_stacksize(*stack_a) > 3)
// 		ft_run(&ft_pb, stack_a, stack_b);
// 	sort_3(stack_a,stack_b);
// 	while (ft_stacksize(*stack_b))
// 	{
// 		a = 0;
// 		b = 0;
// 		get_min_rotate(*stack_a, *stack_b, &a, &b);
// 		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
// 			rotate_same(stack_a, stack_b, a, b);
// 		else
// 			rotate_diff(stack_a, stack_b, a, b);
// 		ft_run(&ft_pa, stack_a, stack_b);
// 	}
// 	// sort_final(stack_a, stack_b);
// }

// void	sort_final(t_stack **stack_a, t_stack **stack_b)
// {
// 	const int	i = stack_idx_minmax(*stack_a, stack_min(*stack_a));

// 	if (i < 0)
// 		ft_run(&ft_rra, stack_a, stack_b);
// 	else
// 		ft_run(&ft_ra, stack_a, stack_b);
// }

// void	sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	if (ft_stacksize(*stack_a) == 2)
// 		ft_run(&ft_sa, stack_a, stack_b);
// 	if (ft_stacksize(*stack_a) == 3)
// 		sort_3(stack_a, stack_b);
// 	else if (ft_stacksize(*stack_a) == 4)
// 		sort_4(stack_a, stack_b);
// 	else if (ft_stacksize(*stack_a) == 5)
// 		sort_5(stack_a, stack_b);
// 	else if (ft_stacksize(*stack_a) > 5)
// 		sort_100(stack_a, stack_b);
// }

int     is_sorted(t_stack *s)
{
    while (s->link)
    {
        if (s->data > s->link->data)
            return (0);
        s = s->link;
    }
    return (1);
}

// int *set_groups(t_stack *stack)
// {
//     int count;
//     int size_stack;
//     int *tab;
//     int i;
// 	int j;
//     int find;
// 	int traverse;

// 	size_stack = ft_stacksize(stack);
// 	tab = (int *)malloc(sizeof(int) * (size_stack + 1));
//     tab = put_stack_in_arr(stack);
//     i = 0;
//     while (i < size_stack)
//     {
//         j = i;
//         int per_grp = tab[i];
//         traverse = 0;
//        while (traverse < size_stack)
// 	    {
// 		    if (per_grp < a[j])
// 		    {
// 		    	per_grp = a[j];
// 		    	// tab[i] = true;
//                 count++;
// 		    }
//             // else{
//                 // tab[j] = false;
//             // }
// 		    j++;
// 		    j = j % size_stack;
// 		    traverse++;
// 	    }
//         tab[i] = count;
//         i++;
//     }
//     return (tab);
// }