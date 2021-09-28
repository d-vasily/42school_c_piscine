/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:23:18 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 18:52:58 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

t_list	*ft_list_find(t_list *begin_list, char *data_ref, int (*cmp)())
{
	if (begin_list == NULL)
		return (NULL);
	while (begin_list != NULL)
	{
		if (!begin_list->src)
			return (NULL);
		if ((*cmp)(begin_list->src, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
