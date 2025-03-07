/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:55:37 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/07 13:14:51 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_img(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &game->img.img_wth, &game->img.img_hgt);
    game->img.floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &game->img.img_wth, &game->img.img_hgt);
    game->img.key = mlx_xpm_file_to_image(game->mlx, "img/key.xpm", &game->img.img_wth, &game->img.img_hgt);
    game->img.zelda = mlx_xpm_file_to_image(game->mlx, "img/zelda.xpm", &game->img.img_wth, &game->img.img_hgt);
    game->img.link_up[0] = mlx_xpm_file_to_image(game->mlx, "img/link_up.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.link_up[1] = mlx_xpm_file_to_image(game->mlx, "img/link_walk_up.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.link_left[0] = mlx_xpm_file_to_image(game->mlx, "img/link_left.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.link_left[1] = mlx_xpm_file_to_image(game->mlx, "img/link_walk_left.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.link_down[0] = mlx_xpm_file_to_image(game->mlx, "img/link_down.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.link_down[1] = mlx_xpm_file_to_image(game->mlx, "img/link_walk_down.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.link_right[0] = mlx_xpm_file_to_image(game->mlx, "img/link_right.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.link_right[1] = mlx_xpm_file_to_image(game->mlx, "img/link_walk_right.xpm", &game->img.img_wth, &game->img.img_hgt);
    game->img.enemy_up[0] = mlx_xpm_file_to_image(game->mlx, "img/enemy_up.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.enemy_up[1] = mlx_xpm_file_to_image(game->mlx, "img/enemy_walk_up.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.enemy_left[0] = mlx_xpm_file_to_image(game->mlx, "img/enemy_left.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.enemy_left[1] = mlx_xpm_file_to_image(game->mlx, "img/enemy_walk_left.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.enemy_down[0] = mlx_xpm_file_to_image(game->mlx, "img/enemy_down.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.enemy_down[1] = mlx_xpm_file_to_image(game->mlx, "img/enemy_walk_down.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.enemy_right[0] = mlx_xpm_file_to_image(game->mlx, "img/enemy_right.xpm", &game->img.img_wth, &game->img.img_hgt);
	game->img.enemy_right[1] = mlx_xpm_file_to_image(game->mlx, "img/enemy_walk_right.xpm", &game->img.img_wth, &game->img.img_hgt);
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
					mlx_put_image_to_window(game->mlx, game->win, game->img.link_down[0], x * 50, y * 50);
				else if (game->map.map[y][x] == 'B')
					mlx_put_image_to_window(game->mlx, game->win, game->img.enemy_down[0], x * 50, y * 50);
				x++;
			}
			y++;
		}
}