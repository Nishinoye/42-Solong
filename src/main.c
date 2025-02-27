/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:25:05 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/27 13:08:26 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int close_window()
{
    printf("Thanks for playing !\n");
    exit(0);
    return (0);
}
int key(int keycode)
{
    if (keycode == 65307)
        close_window();
    return (0);
}
int main()
{
    t_game  mlx;
    int     x;
    int     y;

    printf("🔧 Initialisation de MLX...\n");
    mlx.mlx = mlx_init();
    if (!mlx.mlx)
    {
        printf("❌ Erreur: mlx_init() a échoué !\n");
        return (1);
    }
    printf("✅ MLX initialisé avec succès !\n");

    printf("🔧 Création de la fenêtre...\n");
    mlx_get_screen_size(mlx.mlx, &x, &y);
    mlx.win = mlx_new_window(mlx.mlx, x, y, "so_long");
    if (!mlx.win)
    {
        printf("❌ Erreur: mlx_new_window() a échoué !\n");
        return (1);
    }
    printf("✅ Fenêtre créée avec succès !\n");

    mlx_key_hook(mlx.win, key, NULL);

    mlx_hook(mlx.win, 17, 0, close_window, NULL);

    mlx.wall = mlx_xpm_file_to_image(mlx.mlx, "img/wall.xpm", &mlx.img_wth, &mlx.img_hgt);
    mlx.floor = mlx_xpm_file_to_image(mlx.mlx, "img/floor.xpm", &mlx.img_wth, &mlx.img_hgt);
    mlx.key = mlx_xpm_file_to_image(mlx.mlx, "img/key.xpm", &mlx.img_wth, &mlx.img_hgt);
    mlx.zelda = mlx_xpm_file_to_image(mlx.mlx, "img/zelda.xpm", &mlx.img_wth, &mlx.img_hgt);
    mlx.link_down = mlx_xpm_file_to_image(mlx.mlx, "img/link_down.xpm", &mlx.img_wth, &mlx.img_hgt);
    mlx.enemy_down = mlx_xpm_file_to_image(mlx.mlx, "img/enemy_down.xpm", &mlx.img_wth, &mlx.img_hgt);

    if (render_map(&mlx))
    {
        printf("🔄 Lancement de mlx_loop()...\n");
        mlx_loop(mlx.mlx);
    }
    
    return (0);
}
