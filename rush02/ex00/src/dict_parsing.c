/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:23:15 by shalfbea          #+#    #+#             */
/*   Updated: 2021/09/19 18:53:26 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

int	parse_src(int file, t_list *elem)
{
	int		bytes_read;
	char	cur;
	int		i;

	i = 0;
	bytes_read = read(file, &cur, 1);
	while ((cur == '\n' || ft_is_space(cur)) && bytes_read > 0)
		bytes_read = read(file, &cur, 1);
	while (bytes_read > 0 && cur >= '0' && cur <= '9')
	{
		(elem->src)[i++] = cur;
		bytes_read = read(file, &cur, 1);
	}
	while (bytes_read > 0 && ft_is_space(cur))
		bytes_read = read(file, &cur, 1);
	if (cur != ':')
		return (-1);
	return (bytes_read > 0);
}

int	parse_line(int file, t_list *elem)
{
	int		bytes_read;
	char	cur;
	int		i;

	parse_src(file, elem);
	bytes_read = read(file, &cur, 1);
	while (bytes_read > 0 && ft_is_space(cur))
		bytes_read = read(file, &cur, 1);
	i = 0;
	while (bytes_read > 0 && cur != '\n')
	{
		if (!ft_is_space(cur))
			(elem->dest)[i++] = cur;
		bytes_read = read(file, &cur, 1);
	}
	return ((bytes_read > 0));
}

t_list	*dict_parsing(char *file_name)
{
	t_list	*root;
	t_list	*cur_elem;
	int		bytes_read;
	int		file;

	root = pre_parsing(file_name);
	if (!root)
		return (root);
	cur_elem = root;
	bytes_read = 1;
	file = open(file_name, O_RDONLY);
	if (file < 0)
		return (list_free(&root));
	while (bytes_read)
	{
		cur_elem->src = (char *)malloc(sizeof(char) * (cur_elem->size_src));
		cur_elem->dest = (char *)malloc(sizeof(char) * (cur_elem->size_dest));
		(cur_elem->src)[(cur_elem->size_src) - 1] = '\0';
		(cur_elem->dest)[(cur_elem->size_dest) - 1] = '\0';
		bytes_read = parse_line(file, cur_elem);
		cur_elem = cur_elem->next;
	}
	close(file);
	return (root);
}
