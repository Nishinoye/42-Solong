/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:25:05 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/07 14:31:30 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int close_window()
{
    printf("Thanks for playing !\n");
    exit(0);
    return (0);
}
int key(int keycode, t_game *game)
{
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
    // if (keycode == 32)
    //     hit();
    aff_img(game);
    return (1);
}
int main(int argc, char **argv)
{
    t_game      game;
    int         x;
    int         y;
    
    if (argc != 2)
    {
        printf("Entrez le bon nombre d'arguments");
        return (0);
    }
    game.map.argv = argv;
    game.mlx = mlx_init();
    mlx_get_screen_size(game.mlx, &x, &y);
    game.win = mlx_new_window(game.mlx, x, y, "The Zelda of legend");
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
