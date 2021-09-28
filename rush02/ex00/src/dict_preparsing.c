/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_preparsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:00:21 by shalfbea          #+#    #+#             */
/*   Updated: 2021/09/19 18:53:23 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

int	pre_parse_src(int file, t_list *elem, int *total_read)
{
	int		bytes_read;
	char	cur;

	cur = ':';
	bytes_read = read(file, &cur, 1);
	while ((cur == '\n' || ft_is_space(cur)) && bytes_read > 0)
		bytes_read = read(file, &cur, 1);
	while (bytes_read > 0 && cur >= '0' && cur <= '9')
	{
		(*total_read)++;
		(elem->size_src)++;
		bytes_read = read(file, &cur, 1);
	}
	while (bytes_read > 0 && ft_is_space(cur))
	{
		(*total_read)++;
		bytes_read = read(file, &cur, 1);
	}
	if (cur != ':' && *total_read > 0)
		return (-1);
	return (bytes_read > 0);
}

int	pre_parse_line(int file, t_list *elem)
{
	int		bytes_read;
	char	cur;
	int		total_read;

	total_read = 0;
	bytes_read = pre_parse_src(file, elem, &total_read);
	if (bytes_read < 0 )
		return (-1);
	bytes_read = read(file, &cur, 1);
	while (bytes_read > 0 && ft_is_space(cur))
	{
		bytes_read = read(file, &cur, 1);
		total_read++;
	}
	while (bytes_read > 0 && cur != '\n')
	{
		total_read++;
		if (!ft_is_space(cur))
			(elem->size_dest)++;
		bytes_read = read(file, &cur, 1);
	}
	if (((elem->size_dest == 1) || (elem->size_src == 1)) && total_read > 0)
		return (-1);
	return ((bytes_read > 0));
}

t_list	*pre_parsing(char *file_name)
{
	int		file;
	t_list	*root;
	t_list	*cur_elem;
	int		success;

	success = 1;
	root = list_create_elem();
	cur_elem = root;
	file = open(file_name, O_RDONLY);
	if (file < 0)
		return (list_free(&root));
	while (success > 0)
	{
		success = pre_parse_line(file, cur_elem);
		cur_elem->next = list_create_elem();
		cur_elem = cur_elem->next;
		if (success < 0)
			return (list_free(&root));
	}
	close(file);
	if (success < 0)
		list_free(&root);
	return (root);
}
