/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:54:29 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/24 17:25:33 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "mlx.h"
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
	int		img_wth;
	int		img_hgt;
	int		P;
	int		C;
	int		E;
	int		x;
	int		y;
	int		py;
	int		px;
	char	**map;
}	t_game;

void	render_map(t_game *game, char **map);
void	find_P(t_game *game, char **map);
void	find_C(t_game *game, char **map);
void	find_E(t_game *game, char **map);
int		close_window();
int		key(int keycode);

#endif