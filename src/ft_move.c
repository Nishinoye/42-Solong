/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:13 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/07 14:49:12 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	move_up(t_map *map)
{
	if (map->map[map->py - 1][map->px] != '1')
	{
		if (map->map[map->py - 1][map->px] == 'C')
			map->count++;
		if (map->map[map->py][map->px] == 'E')
		{
			map->py--;
			map->map[map->py][map->px] = 'P';
		}
		else
		{
			if (map->map[map->py - 1][map->px] == 'E')
			{
				if (map->count != map->count_C)
				{
					printf("Il te manque %d clefs", map->count);
					map->map[map->py][map->px] = '0';
					map->py--;
				}
				else
				{
					map->py--;
					map->map[map->py][map->px] = 'P';
				}
			}
			map->map[map->py][map->px] = '0';
			map->py--;
			map->map[map->py][map->px] = 'P';
		}
	}
}

void	move_left(t_map *map)
{
	if (map->map[map->py][map->px - 1] != '1')
	{
		if (map->map[map->py][map->px - 1] == 'C')
		map->count++;
		if (map->map[map->py][map->px] == 'E')
		{
			map->px--;
			map->map[map->py][map->px] = 'P';
		}
		else
		{
			if (map->map[map->py][map->px - 1] == 'E')
			{
				if (map->count != map->count_C)
				{
					printf("Il te manque %d clefs", map->count);
					map->map[map->py][map->px] = '0';
					map->px--;
				}
				else
				{
					map->px--;
					map->map[map->py][map->px] = 'P';
				}
			}
			map->map[map->py][map->px] = '0';
			map->px--;
			map->map[map->py][map->px] = 'P';
		}
	}
}
void	move_down(t_map *map)
{
	if (map->map[map->py + 1][map->px] != '1')
	{
		if (map->map[map->py + 1][map->px] == 'C')
			map->count++;
		if (map->map[map->py][map->px] == 'E')
		{
			map->py++;
			map->map[map->py][map->px] = 'P';
		}
		else
		{
			if (map->map[map->py + 1][map->px] == 'E')
			{
				if (map->count != map->count_C)
				{
					printf("Il te manque %d clefs", map->count);
					map->map[map->py][map->px] = '0';
					map->py++;
				}
				else
				{
					map->py++;
					map->map[map->py][map->px] = 'P';
				}
			}
			map->map[map->py][map->px] = '0';
			map->py++;
			map->map[map->py][map->px] = 'P';
		}
	}
}

void	move_right(t_map *map)
{
	if (map->map[map->py][map->px + 1] != '1')
	{
		if (map->map[map->py][map->px + 1] == 'C')
			map->count++;
		if (map->map[map->py][map->px] == 'E')
		{
			map->px++;
			map->map[map->py][map->px] = 'P';
		}
		else
		{
			if (map->map[map->py][map->px + 1] == 'E')
			{
				if (map->count != map->count_C)
				{
					printf("Il te manque %d clefs", map->count);
					map->map[map->py][map->px] = '0';
					map->px++;
				}
				else
				{
					map->px++;
					map->map[map->py][map->px] = 'P';
				}
			}
			map->map[map->py][map->px] = '0';
			map->px++;
			map->map[map->py][map->px] = 'P';
		}
	}
}