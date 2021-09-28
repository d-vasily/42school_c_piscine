/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:06:35 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/22 19:04:45 by eelroy           ###   ########.fr       */
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

void	s_print(char *str, int descr, int length, int new_line)
{
	if (length == -1)
		length = s_len(str);
	if (descr == 0)
		descr = 1;
	write(descr, str, length);
	if (new_line == 1)
		write(descr, "\n", 1);
	return ;
}
