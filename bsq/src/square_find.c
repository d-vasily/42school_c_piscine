/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyarlat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:12:46 by inyarlat          #+#    #+#             */
/*   Updated: 2021/09/23 11:04:47 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

void	print_matrix_sign(t_map **matrix, t_map_prop *map_props,
t_square_prop *sqr)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	k = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * map_props->rows * (map_props->cols + 1) + 1);
	while (i < map_props->rows)
	{
		j = 0;
		while (j < map_props->cols)
		{
			if (i > (sqr->row - sqr->size) && i <= sqr->row
				&& j > (sqr->col - sqr->size) && j <= sqr->col)
				str[k] = map_props->full;
			else if (matrix[i][j].sign == map_props->empty)
				str[k] = map_props->empty;
			else if (matrix[i][j].sign == map_props->obst)
				str[k] = map_props->obst;
			j++;
			k++;
		}
		str[k] = '\n';
		k++;
		i++;
	}
	str[k] = '\0';
	write(1, str, k);
}

int	char_to_int_convert(t_map matrix, t_map_prop *map_props)
{
	if (matrix.sign == map_props->empty)
		return (1);
	else if (matrix.sign == map_props->obst)
		return (0);
	else
		return (0);
}

int	find_min(int num1, int num2, int num3)
{
	if (num1 < num2)
	{
		if (num1 < num3)
			return (num1);
		else
			return (num3);
	}
	else
	{
		if (num2 < num3)
			return (num2);
		else
			return (num3);
	}
}

void	biggest_square_parse(int i, int j, t_all *all)
{
	t_map			**matrix;
	t_map_prop		*map_props;
	t_square_prop	*result;

	result = all->sqr;
	matrix = all->map;
	map_props = all->m_prop;
	if (i == 0 || j == 0)
		matrix[i][j].size = char_to_int_convert(matrix[i][j], map_props);
	else if (matrix[i][j].sign == map_props->empty)
		matrix[i][j].size = 1 + find_min(matrix[i][j - 1].size,
				matrix[i - 1][j].size, matrix[i - 1][j - 1].size);
	if (matrix[i][j].size > result->size)
	{
		result->size = matrix[i][j].size;
		result->row = i;
		result->col = j;
	}
}
