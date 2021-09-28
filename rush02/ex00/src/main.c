/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:15:40 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 20:38:47 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universe.h"

#define	DEF_DICT_PATH "./dict/standart.dict"
/* 	argc is 1 when there are no arguments | what to do 
	if we return argc 1 or > 3 */

t_list	*check_argv(int argc, char **argv)
{
	t_list	*dict;

	if (argc == 1 || argc > 3)
		return (0);
	if (argc == 2)
		dict = dict_parsing(DEF_DICT_PATH);
	if (argc == 3)
		dict = dict_parsing(argv[1]);
	if (dict == 0)
	{
		gc_putstr("Dict Error\n");
		return (0);
	}
	return (dict);
}

int	main(int argc, char **argv)
{
	t_list	*dict;
	char	*str;

	dict = check_argv(argc, argv);
	if (dict == 0)
		return (0);
	if (argc == 2)
		str = ft_input(argv[1]);
	else
		str = ft_input(argv[2]);
	if (!str)
		gc_putstr("Error");
	else
	{
		arg_parse(str, dict);
	}
	if (str)
		free(str);
	gc_putstr("\n");
	list_free(&dict);
	return (0);
}
