/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:13:54 by eelroy            #+#    #+#             */
/*   Updated: 2021/09/19 19:48:40 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

void	ft_list_push_back(t_list **begin_list, char *key, char *value)
{
	t_list	*x;
	t_list	*tmp;

	x = create_elem_with_data(key, value);
	if (x)
	{
		if (!(*begin_list))
		{
			*begin_list = x;
			return ;
		}
		tmp = *begin_list;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = x;
	}
}
