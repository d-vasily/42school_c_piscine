/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:06:35 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 19:14:55 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

int	s_len(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		++str;
		++len;
	}
	return (len);
}

/* 	additional protection - DESCR can't be 0, as we can't(or can?) 
	write to stdin */
void	s_print(char *str, int descr, int length, int new_line)
{
	if (length == -1)
		length = s_len(str);
	if (descr == 0)
		descr = 1;
	write(descr, str, length);
	if (new_line == 1)
		write(descr, &"\n", 1);
	return ;
}

void	gc_putstr(char *str)
{
	int	length;

	length = s_len(str);
	write(1, str, length);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 - *s2 == 0) && (*s1 != '\0'))
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
