/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:19:04 by eelroy            #+#    #+#             */
/*   Updated: 2021/09/19 18:53:21 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

char	*check_right(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
	{
		str++;
		while (*str == '0')
			str++;
		if (*str != '\0')
			return (0);
		else
			return (str - 1);
	}
	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (*str == '\0')
		return (str - 1);
	if (*str < '0' || *str > '9')
		return (0);
	return (str);
}

char	*ft_input(char *str)
{
	int		count;
	char	*res;
	int		i;

	i = 0;
	count = 0;
	str = check_right(str);
	if (str == 0)
		return (0);
	if (*str == '\0')
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
		count++;
	if (str[count] != '\0')
		return (0);
	res = (char *)malloc(sizeof(char) * count + 1);
	if (!res)
		return (0);
	while (i < count)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
