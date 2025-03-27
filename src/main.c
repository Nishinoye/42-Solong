/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:25:05 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/24 21:13:49 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	close_window(void)
{
	printf("Thanks for playing !\n");
	exit(0);
	return (0);
}

int	key(int keycode, t_game *game)
{
	game->player.walk = !game->player.walk;
	if (keycode == 65307)
		close_window();
	if (keycode == 119)
		move_up(&game->map);
	if (keycode == 97)
		move_left(&game->map);
	if (keycode == 115)
		move_down(&game->map);
	if (keycode == 100)
		move_right(&game->map);
	aff_img(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Entrez le bon nombre d'arguments\n");
		return (0);
	}
	game.map.argv = argv;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 2000, 1000, "The Zelda of legend");
	if (valid_map(&game.map))
	{
		ft_img(&game);
		aff_img(&game);
	}
	mlx_key_hook(game.win, key, &game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
	return (0);
}
