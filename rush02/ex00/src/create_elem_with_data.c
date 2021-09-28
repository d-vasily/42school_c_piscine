/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem_with_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:51:53 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 18:53:28 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

t_list	*create_elem_with_data(char *key, char *value)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->src = key;
	elem->dest = value;
	elem->next = NULL;
	return (elem);
}
