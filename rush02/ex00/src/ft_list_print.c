/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:03:48 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 19:58:55 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"
#include "string_manip.h"

int	check_if_not_valid(t_list *result);

int	ft_list_print(t_list *result)
{
	if (result == NULL)
	{
		gc_putstr("Dict Error");
		return (1);
	}
	if (check_if_not_valid(result))
	{
		gc_putstr("Dict Error");
		return (2);
	}
	while (result != NULL)
	{
		s_print(result->dest, 1, -1, 0);
		if (result->next != NULL)
			gc_putstr(" ");
		result = result->next;
	}
	return (0);
}

int	check_if_not_valid(t_list *result)
{
	while (result != NULL)
	{
		if (result->dest == NULL)
			return (1);
		result = result->next;
	}
	return (0);
}
