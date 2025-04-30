/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:54:29 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/04/30 02:30:38 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13

# endif

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	**argv;
	int		count_p;
	int		count_c;
	int		count_e;
	int		ey;
	int		ex;
	int		py;
	int		px;
	int		count;
	int		move;
}	t_map;

typedef struct s_i
{
	void	*wa;
	void	*f;
	void	*k;
	void	*z;
	void	*l;
	int		w;
	int		h;
}	t_i;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_i			i;
}	t_game;

int		close_window();
int		key(int keycode, t_game *game);
int		valid_map(t_map *map);
int		check_elem(t_map *map);
char	*get_next_line(int fd);
char	**read_map(t_map *map);
void	move_up( t_map *map);
void	move_left( t_map *map);
void	move_down( t_map *map);
void	move_right( t_map *map);
void	ft_img(t_game *mlx);
void	aff_img(t_game *game);
void	ft_exit(t_map *map);
void	*ft_memcpy(void *dest, const void *src, size_t size);

#endif