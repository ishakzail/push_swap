/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:29:08 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 22:24:44 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ps_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

int	parse(char *str, t_stack **stack_1, t_stack **stack_2)
{
	int	len;
	int	(*f)(const char *, const char *, size_t);

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (ps_error());
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 3 && !f(str, "rra", 3)) || (len == 2 && (!f(str, "sa", 2)
				|| !f(str, "ra", 2))))
		ft_run(str, stack_1, 0, -1);
	else if ((len == 3 && !f(str, "rrb", 3)) || (len == 2 && (!f(str, "sb", 2)
				|| !f(str, "rb", 2))))
		ft_run(str, stack_2, 0, -1);
	else if ((len == 3 && !f(str, "rrr", 3)) || (len == 2 && (!f(str, "ss", 2)
				|| !f(str, "pb", 2) || !f(str, "rr", 2))))
		ft_run(str, stack_1, stack_2, -1);
	else if (!f(str, "pa", 2))
		ft_run(str, stack_2, stack_1, -1);
	else
		return (ps_error());
	return (0);
}

void	sort_check(t_stack **stack_a)
{
	char		*cmd;
	t_stack		*stack_b;
	static char	*str;

	stack_b = 0;
	while (1)
	{
		cmd = get_next_line(&str);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (parse(cmd, stack_a, &stack_b))
		{
			free(str);
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (is_sorted(*stack_a) && !ft_stacksize(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	int		len;
	char	**strs;
	t_stack	*stack;

	if (argc > 1)
	{
		strs = 0;
		stack = 0;
		len = split_args(&strs, argv + 1, " ");
		stack = fill_list(len, strs);
		check_dup(strs);
		sort_check(&stack);
		free(strs);
	}
	return (0);
}
