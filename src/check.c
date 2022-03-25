/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:54:15 by izail             #+#    #+#             */
/*   Updated: 2022/03/25 18:15:29 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(char *str)
{
	long	nbr;
	long	signe;

	nbr = 0;
	signe = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		signe = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * signe);
}

int	check_if_int(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[++i]))
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if ((ft_atol(str) < INT_MIN) || (ft_atol(str) > INT_MAX))
		return (0);
	return (1);
}

void	check_dup(char **av)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (av[i])
	{
		dup = ft_strdup(av[i]);
		j = 0;
		while (av[j])
		{
			if (i == j)
				j++;
			else if (ft_atoi(dup) == ft_atoi(av[j]))
			{
				free(dup);
				ft_exit_ps("Values duplicated !", 2);
			}
			else
				j++;
		}
		free(dup);
		i++;
	}
}

int	split_args(char ***strs, char **av, char *sep)
{
	int		ret;
	char	*str;
	char	*tmp;

	str = 0;
	while (*av)
	{
		if (!str)
			str = ft_strdup(*av++);
		else
		{
			tmp = str;
			str = ft_strjoin(str, sep);
			free(tmp);
			tmp = str;
			str = ft_strjoin(str, *av++);
			free(tmp);
		}
	}
	*strs = ft_split(str,*sep);
	free(str);
	ret = 0;
	while ((*strs)[ret])
		ret++;
	return (ret);
}
