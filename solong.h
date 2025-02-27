/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:54:29 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/27 12:57:32 by tedcarpi         ###   ########.fr       */
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*key;
	void	*zelda;
	void	*link_down;
	void	*enemy_down;
	int		img_wth;
	int		img_hgt;
	int		count_P;
	int		count_C;
	int		count_E;
	int		count;
	int		y;
	int		x;
	int		py;
	int		px;
	int		ye;
	int		xe;
	char	**map;
}	t_game;
int		render_map(t_game *game);
int		close_window();
int		key(int keycode);
char	*get_next_line(int fd);

#endif