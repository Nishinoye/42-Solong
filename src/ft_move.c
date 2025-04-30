/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:13 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/04/30 11:55:58 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"


void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n = n % 10 + 48;
	write(1, &n, 1);
}

void	move_up(t_game *g)
{
	if (g->map.map[g->map.py - 1][g->map.px] != '1')
	{
		ft_putnbr(g->map.move++);
		write(1, "\n", 1);
		if (g->map.map[g->map.py - 1][g->map.px] == 'C')
			g->map.count++;
		if (g->map.map[g->map.py - 1][g->map.px] == 'E')
		{
			if (g->map.count != g->map.count_c)
			{
				g->map.map[g->map.py][g->map.px] = 'E';
				g->map.py--;
				g->map.map[g->map.py][g->map.px] = 'P';
			}
			else
				close_window(g);
		}
		else
		{
			g->map.map[g->map.py][g->map.px] = '0';
			g->map.py--;
			g->map.map[g->map.py][g->map.px] = 'P';
		}
	}
}

void	move_left(t_game *g)
{
	if (g->map.map[g->map.py][g->map.px - 1] != '1')
	{
		ft_putnbr(g->map.move++);
		write(1, "\n", 1);
		if (g->map.map[g->map.py][g->map.px - 1] == 'C')
			g->map.count++;
		if (g->map.map[g->map.py][g->map.px - 1] == 'E')
		{
			if (g->map.count != g->map.count_c)
			{
				g->map.map[g->map.py][g->map.px] = 'E';
				g->map.px--;
				g->map.map[g->map.py][g->map.px] = 'P';
			}
			else
				close_window(g);
		}
		else
		{
			g->map.map[g->map.py][g->map.px] = '0';
			g->map.px--;
			g->map.map[g->map.py][g->map.px] = 'P';
		}
	}
}

void	move_down(t_game *g)
{
	if (g->map.map[g->map.py + 1][g->map.px] != '1')
	{
		ft_putnbr(g->map.move++);
		write(1, "\n", 1);
		if (g->map.map[g->map.py + 1][g->map.px] == 'C')
			g->map.count++;
		if (g->map.map[g->map.py + 1][g->map.px] == 'E')
		{
			if (g->map.count != g->map.count_c)
			{
				g->map.map[g->map.py][g->map.px] = 'E';
				g->map.py++;
				g->map.map[g->map.py][g->map.px] = 'P';
			}
			else
				close_window(g);
		}
		else
		{
			g->map.map[g->map.py][g->map.px] = '0';
			g->map.py++;
			g->map.map[g->map.py][g->map.px] = 'P';
		}
	}
}

void	move_right(t_game *g)
{
	if (g->map.map[g->map.py][g->map.px + 1] != '1')
	{
		ft_putnbr(g->map.move++);
		write(1, "\n", 1);
		if (g->map.map[g->map.py][g->map.px + 1] == 'C')
			g->map.count++;
		if (g->map.map[g->map.py][g->map.px + 1] == 'E')
		{
			if (g->map.count != g->map.count_c)
			{
				g->map.map[g->map.py][g->map.px] = 'E';
				g->map.px++;
				g->map.map[g->map.py][g->map.px] = 'P';
			}
			else
				close_window(g);
		}
		else
		{
			g->map.map[g->map.py][g->map.px] = '0';
			g->map.px++;
			g->map.map[g->map.py][g->map.px] = 'P';
		}
	}
}
