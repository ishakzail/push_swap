/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:38:59 by izail             #+#    #+#             */
/*   Updated: 2021/11/15 18:45:58 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	else
	{
		while (*(char *)s1 != '\0')
		{
			str[i] = *(char *)s1++;
			i++;
		}
		while (*(char *)s2 != '\0')
		{
			str[i] = *(char *)s2++;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
