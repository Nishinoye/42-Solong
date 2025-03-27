/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:32:37 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/24 21:13:20 by tedcarpi         ###   ########.fr       */
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
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
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
	map->map = ft_calloc((height + 1), sizeof(char *));
	if (!map->map)
		return (NULL);
	i = 0;
	while (height > i)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map->map);
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
				map->count_c++;
			if (map->map[y][x] == 'E')
				map->count_e++;
			if (map->map[y][x] == 'P')
			{
				map->count_p++;
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
	map->count_c = 0;
	map->count_e = 0;
	map->count_p = 0;
	map->move = 0;
	count_elem(map);
	if (!check_walls(map))
		return (0);
	if (map->count_c < 1)
		return (0);
	if (map->count_e != 1)
		return (0);
	if (map->count_p != 1)
		return (0);
	return (1);
}
