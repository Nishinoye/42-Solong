/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:54:29 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/24 21:22:30 by tedcarpi         ###   ########.fr       */
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

typedef struct s_player
{
	void	*up[2];
	void	*left[2];
	void	*down[2];
	void	*right[2];
	int		w;
	int		h;
	int		walk;
	int		hp;
	int		y;
	int		x;
}	t_player;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*key;
	void	*zelda;
	int		w;
	int		h;
}	t_img;

typedef	struct s_mob
{
	void	*up[2];
	void	*left[2];
	void	*down[2];
	void	*right[2];
}	t_mob;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_img		img;
	t_mob		mob;
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

#endif