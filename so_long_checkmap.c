/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:58:52 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/10 10:45:42 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_map *m)
{
	int	x;
	int	y;

	x = m->x;
	y = m->y;
	while (x--)
	{
		if (m->map[0][x] != '1' || m->map[y - 1][x] != '1')
			ft_error("Error\nIncorrect wall\n");
	}
	x = m->x;
	while (y--)
	{
		if (m->map[y][0] != '1' || m->map[y][x - 1] != '1')
			ft_error("Error\nIncorrect wall\n");
	}
	return (1);
}

int	count_check_comps(t_map *m)
{
	int	x;
	int	y;

	m->player = 0;
	m->exit = 0;
	m->coin = 0;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
				m->player++;
			else if (m->map[y][x] == 'C')
				m->coin++;
			else if (m->map[y][x] == 'E')
				m->exit++;
			x++;
		}
		y++;
	}
	if (m->player != 1 || m->exit != 1 || m->coin < 1)
		return (0);
	return (1);
}

int	checks(t_map *m)
{
	if (!count_check_comps(m))
	{
		ft_printf("Error\nIncorrect comps\n");
		free_map(m);
		return (0);
	}
	if (!check_wall(m))
	{
		ft_error("Error\nIncorrect wall\n");
		free_map(m);
		return (0);
	}
	if (!flood_fill(m))
	{
		ft_error("Error\nNo playable\n");
		free_map(m);
		return (0);
	}
	return (1);
}
