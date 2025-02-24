/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:32:37 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/24 17:43:43 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../solong.h"

int	map_height(char *map_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	while (line = get_next_line(fd))
	{
		free(line);
		height++;
	}
	return (height);
}

void	read_map(char *map_name)
{
	int		fd;
	int		i;
	int		height;
	t_game	*game;
	
	height = map_height(map_name);
	if (height <= 0)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->map = malloc(sizeof(char *) * (height + 1));
	if (!game->map)
		return (NULL);
	i = 0;
	while (i < height)
		game->map[i++] = get_next_line(fd);
	close(fd);
}

int	check_walls(char **map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map[0][y])
	{
		if (map[0][y] != '1' || map[map_height(map) - 1][y] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (map[x])
	{
		if (map[x][0] != '1' || map[x][ft_strlen(map[i]) - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

void	count_eleme(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[x][y] == 'C')
				game->C++;
			if (game->map[x][y] == 'E')
				game->E++;
			if (game->map[x][y] == 'P')
				game->P++;
			x++;
		}
		y++;
	}
}

int	check_map(t_game *game)
{	
	if (!check_walls(game->map))
		return (0);
	if (game->C != 1)
		return (0);
	if (game->E != 1)
		return (0);
	if (game->P != 1)
		return (0);
	return (1);
	// if (count_eleme(map, 'B') != 1)
	// 	return (0);
	//	BONUS
}

void	fill_map(int y, int x, char **temp_map)
{
	t_game	*game;
	
	if (game->map[game->py][game->px] == 1 || game->map[game->py][game->px] == 'V')
		return;
	game->map[game->y][game->x] = 'V';
	fill_map(y + 1, x, temp_map);
	fill_map(y - 1, x, temp_map);
	fill_map(y, x + 1, temp_map);
	fill_map(y, x - 1, temp_map);
}

int	valid_map(t_game *map)
{
	char	**temp_map;

	temp_map = copy_map;
	find_P(map);
	fill_map(map->py, map->px, temp_map);
	find_E(map, map);
	if (map[map->py][map->px] != 'V')
	{
		free_map(temp);
		return (0);
	}
	free_map(temp);
	return (1);
}

void	render_map(t_game *game, char **map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 50, y * 50);
			else if (map [y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, x * 50, y * 50);
			x++;
		}
		y++;
	}
}