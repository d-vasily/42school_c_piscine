/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:58:43 by eelroy            #+#    #+#             */
/*   Updated: 2021/09/23 11:04:03 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "universe.h"

void	ft_final(t_all *all)
{
	print_matrix_sign(all->map, all->m_prop, all->sqr);
	ft_free_map(all, all->m_prop->rows - 1);
}

int	ft_iter_j(int i, int j, t_all *all)
{
	while (j < all->m_prop->cols)
	{
		all->map[i][j].sign = all->data[j];
		if (all->data[j] == all->m_prop->empty)
			all->map[i][j].size = 1;
		else if (all->data[j] == all->m_prop->obst)
			all->map[i][j].size = 0;
		else
		{
			ft_error_free("map error", i, all);
			return (0);
		}
		biggest_square_parse(i, j, all);
		j++;
	}
	if (all->data[j] != '\n')
	{
		ft_error_free("map error", i, all);
		return (0);
	}
	return (1);
}

void	ft_iter(int fd, int i, t_all *all)
{
	while (i < all->m_prop->rows && read(fd,
			all->data, all->m_prop->cols + 1) == all->m_prop->cols + 1)
	{
		all->map[i] = (t_map *)malloc(sizeof(t_map) * all->m_prop->cols);
		if (!all->map[i])
		{
			ft_error_free("Error memory", 1, all);
			return ;
		}
		if (ft_iter_j(i, 0, all) != 1)
			return ;
		i++;
	}
	if (i != all->m_prop->rows)
	{
		ft_error_free("map error", i, all);
		return ;
	}
	if (read(fd, all->data, 1) != 0)
	{
		ft_error_free("map error", i, all);
		return ;
	}
	ft_final(all);
}

void	ft_get_m_prop(int fd, int i, t_all *all)
{
	all->m_prop->cols = i;
	if (!all->map)
	{
		s_print("Error memory", 2, -1, 1);
		return ;
	}
	i = 0;
	all->map[0] = (t_map *)malloc(sizeof(t_map) * all->m_prop->cols);
	if (!all->map[0])
	{
		s_print("Error memory", 2, -1, 1);
		return ;
	}
	while (i < all->m_prop->cols)
	{
		all->map[0][i].sign = all->data[i];
		if (all->data[i] == all->m_prop->empty)
			all->map[0][i].size = 1;
		else
			all->map[0][i].size = 0;
		biggest_square_parse(0, i, all);
		i++;
	}
	ft_iter(fd, 1, all);
}

void	ft_read_first_str(int fd, int size, t_all *all)
{
	char	buf;
	int		i;

	all->map = (t_map **)malloc(sizeof(t_map *) * all->m_prop->rows);
	i = 0;
	while ((read(fd, &buf, 1)) && (buf == all->m_prop->empty
			|| buf == all->m_prop->obst))
	{
		all->data[i] = buf;
		i++;
		if (i == size - 2)
		{
			all->data[i + 1] = '\0';
			all->data = ft_add_size(all->data, size);
			if (!all->data)
				return ;
			size *= 2;
		}	
	}
	if (i == 0 || buf != '\n' || ft_check_chars(all))
	{
		s_print("map error", 2, -1, 1);
		return ;
	}
	ft_get_m_prop(fd, i, all);
}
