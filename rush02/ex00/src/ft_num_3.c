/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:09:34 by eelroy            #+#    #+#             */
/*   Updated: 2021/09/21 15:56:14 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

int	s_len(char *str);

void	ft_push_num(t_list *lst, t_list **res)
{
	if (lst)
		ft_list_push_back(res, NULL, lst->dest);
	else
		ft_list_push_back(res, NULL, NULL);
	return ;
}

void	ft_push_zero(int class, t_list *lst, t_list **res)
{
	int		i;
	char	*s;
	t_list	*x;

	if (class == 0)
		return ;
	i = 1;
	s = (char *)malloc(sizeof(char) * (2 + 3 * class));
	if (!s)
		return ;
	s[0] = '1';
	while (i < 1 + 3 * class)
	{
		s[i] = '0';
		i++;
	}
	s[i] = '\0';
	x = ft_list_find(lst, s, ft_strcmp);
	ft_push_num(x, res);
	free(s);
}

void	ft_two(char *str, t_list *lst, t_list **res)
{
	t_list	*x;
	char	*s;

	if (str[0] == '1' || str[1] == '0')
	{
		x = ft_list_find(lst, str, ft_strcmp);
		ft_push_num(x, res);
		return ;
	}
	s = (char *)malloc(sizeof(char) * 3);
	if (!s)
		return ;
	s[0] = str[0];
	s[1] = '0';
	s[2] = '\0';
	x = ft_list_find(lst, s, ft_strcmp);
	ft_push_num(x, res);
	free(s);
	s = (char *)malloc(sizeof(char) * 3);
	if (!s)
		return ;
	s[0] = str[1];
	s[1] = '\0';
	ft_push_num(ft_list_find(lst, s, ft_strcmp), res);
	free(s);
}

void	ft_three(char *str, t_list *lst, t_list **res)
{
	t_list	*x;
	char	*s;
	int		size;

	s = (char *)malloc(sizeof(char) * 2);
	s[0] = str[0];
	s[1] = '\0';
	x = ft_list_find(lst, s, ft_strcmp);
	ft_push_num(x, res);
	x = ft_list_find(lst, "100", ft_strcmp);
	ft_push_num(x, res);
	free(s);
	str++;
	while (*str == '0')
		str++;
	size = 0;
	while (str[size])
		size++;
	if (size == 2)
		ft_two(str, lst, res);
	if (size == 1)
	{
		x = ft_list_find(lst, str, ft_strcmp);
		ft_push_num(x, res);
	}
}

void	ft_num_3(char *str, t_list *lst, int class, t_list **result)
{
	t_list	*x;
	int		i;
	int		slen;

	i = 0;
	slen = s_len(str);
	while (*str == '0')
		str++;
	while (str[i])
		i++;
	if (i == 1)
	{
		x = ft_list_find(lst, str, ft_strcmp);
		ft_push_num(x, result);
	}
	if (i == 2)
		ft_two(str, lst, result);
	if (i == 3)
		ft_three(str, lst, result);
	if (i == 0 && class == 0 && slen != 3)
		ft_push_num(ft_list_find(lst, "0", ft_strcmp), result);
	if (i != 0)
		ft_push_zero(class, lst, result);
}
