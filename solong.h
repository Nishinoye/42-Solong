/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:54:29 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/07 14:29:58 by tedcarpi         ###   ########.fr       */
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

typedef struct s_player
{
	int	hp;
	int	y;
	int	x;
}	t_player;

typedef struct s_map
{
	char	**map;
	char	**argv;
	int		count_P;
	int		count_C;
	int		count_E;
	int		ey;
	int		ex;
	int		py;
	int		px;
	int		count;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*key;
	void	*zelda;
	void	*link_up[2];
	void	*link_left[2];
	void	*link_down[2];
	void	*link_right[2];
	void	*enemy_up[2];
	void	*enemy_left[2];
	void	*enemy_down[2];
	void	*enemy_right[2];
	int		img_wth;
	int		img_hgt;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_img		img;
}	t_game;

int		close_window();
int		key(int keycode, t_game *game);
int		valid_map(t_map *map);
char	*get_next_line(int fd);
void	move_up( t_map *map);
void	move_left( t_map *map);
void	move_down( t_map *map);
void	move_right( t_map *map);
void	ft_img(t_game *mlx);
void	aff_img(t_game *game);
void	ft_exit(t_map *map);

#endif