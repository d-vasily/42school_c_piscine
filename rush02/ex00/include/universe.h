/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:47:23 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/19 19:57:32 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIVERSE_H
# define UNIVERSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	struct s_list	*next;
	int				size_src;
	int				size_dest;
	char			*src;
	char			*dest;
}					t_list;

t_list	*list_create_elem(void);
void	list_show_all_elements(t_list *root);
char	*list_find(t_list *root, char *str);
t_list	*list_free(t_list **root);

int		parse_src(int file, t_list *elem);
int		parse_line(int file, t_list *elem);
t_list	*dict_parsing(char *file_name);

int		pre_parse_src(int file, t_list *elem, int *total_read);
int		pre_parse_line(int file, t_list *elem);
t_list	*pre_parsing(char *file_name);

t_list	*create_elem_with_data(char *key, char *value);
void	ft_list_push_front(t_list **begin_list, char *key, char *value);
void	ft_list_push_back(t_list **begin_list, char *key, char *value);
t_list	*ft_list_find(t_list *begin_list, char *data_ref, int (*cmp)());
int		ft_list_print(t_list *result);
void	ft_num_3(char *str, t_list *lst, int class, t_list **result);
char	*ft_input(char *str);
void	copy_short_str(char *str, int len, char *buff);
int		arg_parse(char *arg, t_list *lst);
void	print_list(t_list *lst);

int		ft_strcmp(char *s1, char *s2);
int		ft_is_space(char c);
void	gc_putstr(char *str);

#endif
