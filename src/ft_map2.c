/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:11:30 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/04/30 11:29:29 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (size == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dest;
	while (i < size)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	return (dest);
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
		return ;
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
		return (NULL);
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
		return ;
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
		return (-1);
	if (!check_elem(map))
		return (0);
	temp_map = copy_map(map);
	map->count = 0;
	fill_map(map->py, map->px, temp_map, map);
	if (map->count != map->count_c)
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
