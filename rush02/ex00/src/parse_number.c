/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:51:41 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 20:44:25 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"
#include "string_manip.h"

void	copy_short_str(char *str, int len, char *buff);
void	clear_result_list(t_list *begin_list);

/* body - сколько раз в валидной строке, которая обозначает число
	встречается блок в 3 символа; tail - остаток от деления на 3 */
/* arg - is argument, lst is a valid list from dictionary */
int	arg_parse(char *arg, t_list *lst)
{
	t_list	*result;
	char	buff[4];
	int		body;
	int		tail;

	result = NULL;
	body = s_len(arg) / 3;
	tail = s_len(arg) % 3;
	if (tail != 0)
	{
		copy_short_str(arg, tail, buff);
		ft_num_3(buff, lst, body, &result);
		arg += tail;
	}
	--body;
	while (body >= 0)
	{
		copy_short_str(arg, 3, buff);
		ft_num_3(buff, lst, body, &result);
		arg += 3;
		--body;
	}
	tail = ft_list_print(result);
	clear_result_list(result);
	return (tail);
}

/* лист результата хранит в себе лишь ссылки на строки оригинального листа
	или NULL, поэтому освобождать память под сами поля структуры нам не надо */
void	clear_result_list(t_list *begin_list)
{
	t_list	*elem;

	if (begin_list == NULL)
		return ;
	while (begin_list != NULL)
	{
		elem = begin_list->next;
		free(begin_list);
		begin_list = elem;
	}
	return ;
}

/* копируем в буфер из 3х элементов от 1 до 3 элементов строки str */
void	copy_short_str(char *str, int len, char *buff)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0' && i < len)
	{
		*(buff + i) = *(str + i);
		++i;
	}
	*(buff + i) = '\0';
	*(buff + 3) = '\0';
	return ;
}
