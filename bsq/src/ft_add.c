/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:46:32 by eelroy            #+#    #+#             */
/*   Updated: 2021/09/22 18:40:34 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[i])
	{
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}

int	ft_atoi(char *str, int n)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (i <= n)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

char	*ft_add_size(char *src, int size)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * size * 2);
	if (!res)
	{
		s_print("Memory error", 2, -1, 1);
		return (0);
	}
	res = ft_strcat(res, src);
	free(src);
	return (res);
}

void	ft_error_free(char *str, int max, t_all *all)
{
	s_print(str, 2, -1, 1);
	ft_free_map(all, max);
}

int	ft_check_chars(t_all *all)
{
	if (all->m_prop->empty == all->m_prop->full)
		return (1);
	if (all->m_prop->obst == all->m_prop->full)
		return (1);
	if (all->m_prop->empty == all->m_prop->obst)
		return (1);
	return (0);
}
