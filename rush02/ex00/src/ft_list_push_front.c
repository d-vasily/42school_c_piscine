/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:23:38 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 18:53:03 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

void	ft_list_push_front(t_list **begin_list, char *key, char *value)
{
	t_list	*elem;

	elem = create_elem_with_data(key, value);
	if (!elem)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
	return ;
}
