/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:52:46 by eelroy            #+#    #+#             */
/*   Updated: 2021/09/22 20:24:51 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "universe.h"

void	ft_num_prop(int fd, char buf, t_all *all)
{
	char	num[15];
	int		i;

	num[0] = buf;
	i = 1;
	while (read(fd, &buf, 1) && i < 14 && buf >= '!' && buf <= 126)
	{
		num[i] = buf;
		i++;
	}
	if (i < 4 || i == 14 || buf != '\n')
	{
		s_print("map error", 2, -1, 1);
		return ;
	}
	all->m_prop->rows = ft_atoi(num, i - 4);
	if (all->m_prop->rows == 0)
	{
		s_print("map error", 2, -1, 1);
		return ;
	}
	all->m_prop->empty = num[i - 3];
	all->m_prop->obst = num[i - 2];
	all->m_prop->full = num[i - 1];
	ft_read_first_str(fd, B_SIZE, all);
}

void	ft_read_sign_zero(int fd, t_all *all)
{
	char	buf;
	int		n;

	if (read(fd, &buf, 1) && buf == '+')
		read(fd, &buf, 1);
	if (buf < '0' || buf > '9')
	{
		s_print("map error", 2, -1, 1);
		return ;
	}
	n = 1;
	while (buf == '0' && n)
		n = read(fd, &buf, 1);
	if (n == 0 || buf < '1' || buf > '9')
	{
		s_print("map error", 2, -1, 1);
		return ;
	}
	ft_num_prop(fd, buf, all);
}

int	ft_open(char *file_name, t_all *all)
{
	int			fd;

	all->m_prop = (t_map_prop *)malloc(sizeof(t_map_prop));
	all->sqr = (t_square_prop *)malloc(sizeof(t_square_prop));
	all->data = (char *)malloc(sizeof(char) * B_SIZE + 1);
	if (!all->m_prop || !all->sqr || !all->data)
	{
		s_print("Error memory", 2, -1, 1);
		return (0);
	}
	fd = 0;
	if (file_name != 0)
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			s_print(file_name, 2, -1, 0);
			s_print(" : Read file error", 2, -1, 1);
			return (0);
		}
	}
	ft_read_sign_zero(fd, all);
	if (fd)
		close(fd);
	return (1);
}

void	ft_start(int argc, char **argv)
{
	int		i;
	t_all	*all;

	i = 1;
	if (argc == 1)
	{
		all = (t_all *)malloc(sizeof(t_all));
		if (ft_open(0, all))
			ft_free(all);
	}
	else
	{
		while (argv[i])
		{
			all = (t_all *)malloc(sizeof(t_all));
			if (ft_open(argv[i], all))
				ft_free(all);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
}
