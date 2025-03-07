/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:32:37 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/07 14:10:25 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	map_height(t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map->argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		height++;
	}
	return (height);
}

char	**read_map(t_map *map)
{
	int		fd;
	int		i;
	int		height;

	height = map_height(map);
	if (height <= 0)
		return (NULL);
	fd = open(map->argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	map->map =ft_calloc((height + 1), sizeof(char *));
	if (!map->map)
		return (NULL);
	i = 0;
	while (height > i)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return(map->map);
}

int	check_walls(t_map *map)
{
	int	x;
	int	y;
	int	len;
	int	height;

	len = ft_strlen(map->map[0]);
	height = map_height(map);
	y = 0;
	while (y < height)
	{
		if (map->map[y][0] != '1' || map->map[y][len - 2] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (x < len - 1)
	{
		if (map->map[0][x] != '1' || map->map[height - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

void	count_elem(t_map *map)
{
	int			x;
	int			y;

	y = 1;
	while (map->map[y])
	{
		x = 1;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
				map->count_C++;
			if (map->map[y][x] == 'E')
				map->count_E++;
			if (map->map[y][x] == 'P')
			{
				map->count_P++;
				map->py = y;
				map->px = x;
			}
			x++;
		}
		y++;
	}
}

int	check_elem(t_map *map)
{
	map->py = 0;
	map->px = 0;
	map->count_C = 0;
	map->count_E = 0;
	map->count_P = 0;
	count_elem(map);
	if (!check_walls(map))
		return (0);
	if (map->count_C < 1)
		return (0);
	if (map->count_E != 1)
		return (0);
	if (map->count_P != 1)
		return (0);
	return (1);
}

void	fill_map(int y, int x, char **temp_map, t_map *map)
{
	if (temp_map[y][x] == 'E')
	{
		map->ey = y;
		map->ex = x;
	}
	if (temp_map[y][x] == 'C')
		map->count++;
	if (temp_map[y][x] == '1' || temp_map[y][x] == 'V')
		return;
	temp_map[y][x] = 'V';
	fill_map(y + 1, x, temp_map, map);
	fill_map(y - 1, x, temp_map, map);
	fill_map(y, x + 1, temp_map, map);
	fill_map(y, x - 1, temp_map, map);
}

char	**copy_map(t_map *map)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map->map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	if (!new_map)
		return(NULL);
	i = 0;
	while (map->map[i])
	{
		new_map[i] = ft_strdup(map->map[i]);
		if (!new_map[i])
		{
			while (i >= 0)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	valid_map(t_map *map)
{
	char	**temp_map;

	if (!read_map(map))
		return (0);
	if (!check_elem(map))
		return (0);
	temp_map = copy_map(map);
	map->count = 0;
	fill_map(map->py, map->px, temp_map, map);
	if (map->count != map->count_C)
		return (0);
	map->count = 0;
	if (temp_map[map->ey][map->ex] != 'V')
	{
		free_map(temp_map);
		return (0);
	}
	free_map(temp_map);
	
	return (1);
}
