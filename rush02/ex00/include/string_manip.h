/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:14:51 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 18:26:43 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_MANIP_H
# define STRING_MANIP_H

/* for functions that use WRITE to output */
# include <unistd.h>

void	gc_putstr(char *str);

/* counts length of the string */
int		s_len(char *str);

/* 	1) prints to file or source that is defined by DESCR. DESCR
must be 1 for stdout 2 for stderror and CAN'T BE 0 (stdin); */
/*	2) if LENGTH is (-1), then it counts length with S_LEN function,
otherwise - it outputs LENGTH characters into the output; */
/*	3) if NEW_LINE is (1) then it also outputs ('\n') after the STR */
void	s_print(char *str, int descr, int length, int new_line);

/* returns > 0 if s1>s2, 0 if equal and < 0 otherwise */
int		ft_strcmp(char *s1, char *s2);

#endif