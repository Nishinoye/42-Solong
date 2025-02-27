/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:48:11 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/02/25 15:47:42 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	find_P(t_game *map, char elem)
{
	int	y;
	int	x;
	
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == elem)
			{
				map->py = y;
				map->px = x;
			}
			x++;
		}
		y++;
	}
}