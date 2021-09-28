/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:47:23 by gcoralie          #+#    #+#             */
/*   Updated: 2021/09/22 19:48:15 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIVERSE_H
# define UNIVERSE_H
# define B_SIZE 4096

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int		size;
	char	sign;
}		t_map;

typedef struct s_map_prop
{
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
}		t_map_prop;

typedef struct s_square_prop
{
	int	size;
	int	row;
	int	col;
}		t_square_prop;

typedef struct s_all
{
	t_map			**map;
	t_map_prop		*m_prop;
	t_square_prop	*sqr;
	char			*data;

}	t_all;

void	ft_free(t_all *all);
void	ft_free_map(t_all *all, int max);
void	ft_error_free(char *str, int max, t_all *all);
int		ft_check_chars(t_all *all);

void	ft_start(int argc, char **argv);
void	ft_read_first_str(int fd, int size, t_all *all);

char	*ft_strcat(char *dest, char *src);
int		ft_atoi(char *str, int i);
char	*ft_add_size(char *src, int size);

int		s_len(char *str);
void	s_print(char *str, int descr, int length, int new_line);

void	print_matrix_sign(t_map **matrix,
			t_map_prop *map_props, t_square_prop *sqr);
void	biggest_square_parse(int i, int j, t_all *all);

#endif
