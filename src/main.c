/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:25:05 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/04/30 11:38:55 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (keycode == 119)
		move_up(game);
	if (keycode == 97)
		move_left(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 100)
		move_right(game);
	aff_img(game);
	return (1);
}

void	exit_(t_game *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map.map);
	free(game->mlx);
}

int	main(int argc, char **argv)
{
	int		i;
	t_game	game;

	if (argc != 2)
	{
		write(1, "Entrez le bon nombre d'arguments\n", 33);
		return (0);
	}
	game.map.argv = argv;
	i = valid_map(&game.map);
	if (i < 1)
	{
		if (i != -1)
			free_map(game.map.map);
		return (0);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 2000, 1000, "The Zelda of legend");
	ft_img(&game);
	aff_img(&game);
	mlx_key_hook(game.win, key, &game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
	exit_(&game);
	return (0);
}
