/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:12:52 by eelroy            #+#    #+#             */
/*   Updated: 2021/09/22 20:36:54 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "universe.h"

void	ft_free_map(t_all *all, int max)
{
	int	i;

	if (max > all->m_prop->rows - 1)
		max = all->m_prop->rows - 1;
	i = 0;
	while (i <= max)
	{
		if (all->map[i])
			free(all->map[i]);
		i++;
	}
}

void	ft_free(t_all *all)
{
	if (!all)
		return ;
	if (all->data)
		free(all->data);
	if (all->map)
		free(all->map);
	if (all->m_prop)
		free(all->m_prop);
	if (all->sqr)
		free(all->sqr);
	free(all);
}
