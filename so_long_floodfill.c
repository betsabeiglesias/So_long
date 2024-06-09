/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_floodfill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:04:41 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/10 14:00:11 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
			{
				m->player_y = y;
				m->player_x = x;
			}
			x++;
		}
		y++;
	}
}

void	playable(t_map *m, int y, int x)
{
	if (m->map[y][x] == 'C')
		m->coin_flood++;
	if (m->map[y][x] == 'E')
		m->exit_flood = true;
	if (m->map[y][x] == '1' || m->map[y][x] == 'F')
		return ;
	m->map[y][x] = 'F';
	playable(m, y + 1, x);
	playable(m, y - 1, x);
	playable(m, y, x + 1);
	playable(m, y, x - 1);
}

int	flood_fill(t_map *m)
{
	m->coin_flood = 0;
	search_player(m);
	playable(m, m->player_y, m->player_x);
	if (m->coin_flood != m->coin || m->exit_flood == false)
		return (0);
	return (1);
}
