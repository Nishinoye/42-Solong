/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:25:05 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/23 15:52:32 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int close_window()
{
    printf("✅ Fenêtre fermée avec succès !\n");
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
    void *mlx;
    void *win;
    int     x;
    int     y;

    printf("🔧 Initialisation de MLX...\n");
    mlx = mlx_init();
    if (!mlx)
    {
        printf("❌ Erreur: mlx_init() a échoué !\n");
        return (1);
    }
    printf("✅ MLX initialisé avec succès !\n");

    printf("🔧 Création de la fenêtre...\n");
    mlx_get_screen_size(mlx, &x, &y);
    win = mlx_new_window(mlx, x, y, "so_long");
    if (!win)
    {
        printf("❌ Erreur: mlx_new_window() a échoué !\n");
        return (1);
    }
    printf("✅ Fenêtre créée avec succès !\n");

    mlx_string_put(mlx, win, 390, 298, 0xFFFFFF, "Wake up");

    mlx_key_hook(win, key, NULL);

    mlx_hook(win, 17, 0, close_window, NULL);

    printf("🔄 Lancement de mlx_loop()...\n");
    mlx_loop(mlx);
    
    return (0);
}
