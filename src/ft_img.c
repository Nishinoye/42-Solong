/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:55:37 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/24 21:27:50 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_img(t_game *g)
{
	void	*(*f)(void *, char *, int *, int *);

	f = mlx_xpm_file_to_image;
	g->img.wall = f(g->mlx, "img/wall.xpm", &g->img.w, &g->img.h);
	g->img.floor = f(g->mlx, "img/floor.xpm", &g->img.w, &g->img.h);
	g->img.key = f(g->mlx, "img/key.xpm", &g->img.w, &g->img.h);
	g->img.zelda = f(g->mlx, "img/zelda.xpm", &g->img.w, &g->img.h);
	g->player.up[0] = f(g->mlx, "img/l_up.xpm", &g->img.w, &g->player.h);
	g->player.up[1] = f(g->mlx, "img/lw_up.xpm", &g->img.w, &g->player.h);
	g->player.left[0] = f(g->mlx, "img/l_left.xpm", &g->img.w, &g->player.h);
	g->player.left[1] = f(g->mlx, "img/lw_left.xpm", &g->img.w, &g->player.h);
	g->player.down[0] = f(g->mlx, "img/l_down.xpm", &g->img.w, &g->player.h);
	g->player.down[1] = f(g->mlx, "img/lw_down.xpm", &g->img.w, &g->player.h);
	g->player.right[0] = f(g->mlx, "img/l_right.xpm", &g->img.w, &g->player.h);
	g->player.right[1] = f(g->mlx, "img/lw_right.xpm", &g->img.w, &g->player.h);
	g->mob.up[0] = f(g->mlx, "img/m_up.xpm", &g->img.w, &g->img.h);
	g->mob.up[1] = f(g->mlx, "img/mw_up.xpm", &g->img.w, &g->img.h);
	g->mob.left[0] = f(g->mlx, "img/m_left.xpm", &g->img.w, &g->img.h);
	g->mob.left[1] = f(g->mlx, "img/mw_left.xpm", &g->img.w, &g->img.h);
	g->mob.down[0] = f(g->mlx, "img/m_down.xpm", &g->img.w, &g->img.h);
	g->mob.down[1] = f(g->mlx, "img/mw_down.xpm", &g->img.w, &g->img.h);
	g->mob.right[0] = f(g->mlx, "img/m_right.xpm", &g->img.w, &g->img.h);
	g->mob.right[1] = f(g->mlx, "img/mw_right.xpm", &g->img.w, &g->img.h);
}

void	aff_img(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x * 50, y * 50);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.key, x * 50, y * 50);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.zelda, x * 50, y * 50);
			else if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img.floor, x * 50, y * 50);
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.down[0], x * 50, y * 50);
			else if (game->map.map[y][x] == 'B')
				mlx_put_image_to_window(game->mlx, game->win, game->mob.down[0], x * 50, y * 50);
			x++;
		}
		y++;
	}
}
