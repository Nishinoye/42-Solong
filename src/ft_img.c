/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:55:37 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/04/30 10:00:12 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_img(t_game *g)
{
	void	*(*f)(void *, char *, int *, int *);

	f = mlx_xpm_file_to_image;
	g->i.wa = f(g->mlx, "img/wall.xpm", &g->i.w, &g->i.h);
	g->i.f = f(g->mlx, "img/floor.xpm", &g->i.w, &g->i.h);
	g->i.k = f(g->mlx, "img/key.xpm", &g->i.w, &g->i.h);
	g->i.z = f(g->mlx, "img/zelda.xpm", &g->i.w, &g->i.h);
	g->i.l = f(g->mlx, "img/l_down.xpm", &g->i.w, &g->i.h);
}

void	aff_img(t_game *g)
{
	int	y;
	int	x;
	int	(*f)(void *, void *, void *, int, int);

	y = 0;
	f = mlx_put_image_to_window;
	while (g->map.map[y])
	{
		x = 0;
		while (g->map.map[y][x])
		{
			if (g->map.map[y][x] == '1')
				f(g->mlx, g->win, g->i.wa, x * 50, y * 50);
			else if (g->map.map[y][x] == 'C')
				f(g->mlx, g->win, g->i.k, x * 50, y * 50);
			else if (g->map.map[y][x] == 'E')
				f(g->mlx, g->win, g->i.z, x * 50, y * 50);
			else if (g->map.map[y][x] == '0')
				f(g->mlx, g->win, g->i.f, x * 50, y * 50);
			else if (g->map.map[y][x] == 'P')
				f(g->mlx, g->win, g->i.l, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	destroy_img(t_game *g)
{
	mlx_destroy_image(g->mlx, g->i.wa);
	mlx_destroy_image(g->mlx, g->i.f);
	mlx_destroy_image(g->mlx, g->i.z);
	mlx_destroy_image(g->mlx, g->i.k);
	mlx_destroy_image(g->mlx, g->i.l);
}
