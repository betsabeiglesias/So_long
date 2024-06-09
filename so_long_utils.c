/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:16:15 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/10 10:31:23 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *s)
{
	ft_printf("%s", s);
	exit(0);
}

int	finish_game(t_map *m)
{
	destroy_window(m);
	free(m->mlx);
	exit(0);
}

void	collect_coins(t_map *m, int y, int x)
{
	if (m->map[y][x] == 'C')
		m->coin--;
}

void	free_map(t_map *m)
{
	int	y;

	y = 0;
	while (m->map[y])
	{
		free(m->map[y]);
		y++;
	}
	free(m->map);
	m->map = NULL;
}
