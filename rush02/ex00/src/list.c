/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:57:33 by shalfbea          #+#    #+#             */
/*   Updated: 2021/09/19 19:12:30 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

t_list	*list_create_elem(void)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	elem->next = NULL;
	elem->size_src = 1;
	elem->size_dest = 1;
	elem->src = NULL;
	elem->dest = NULL;
	return (elem);
}

char	*list_find(t_list *root, char *str)
{
	int	checked;
	int	i;

	i = 0;
	checked = 0;
	if (!root)
		return (NULL);
	while (root->next)
	{
		i = 0;
		if (!ft_strcmp(str, root->src))
			return ((char *)(root->dest));
		root = root->next;
	}
	return (NULL);
}

t_list	*list_free(t_list **root)
{
	t_list	*tmp;
	t_list	*head;

	head = *root;
	while (head)
	{	
		tmp = head;
		head = head->next;
		free(tmp->src);
		free(tmp->dest);
		free(tmp);
	}
	*root = NULL;
	return (NULL);
}
