/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:03:09 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/10 14:09:39 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keyhook(int key, t_map *m)
{
	if (key == KEY_ESQ)
		exit(0);
	if (key == KEY_UP || key == 13)
		move_up(m);
	if (key == KEY_DOWN || key == 1)
		move_down(m);
	if (key == KEY_RIGHT || key == 2)
		move_right(m);
	if (key == KEY_LEFT || key == 0)
		move_left(m);
	mlx_clear_window(m->mlx, m->window);
	render_window(m);
	return (0);
}

void	move_up(t_map *m)
{
	if (m->map[m->player_y - 1][m->player_x] != '1')
	{
		m->move++;
		ft_printf("%d Movements\n", m->move);
		if (m->map[m->player_y - 1][m->player_x] == 'E')
		{
			if (m->coin == 0)
			{
				ft_printf("FINISH!\n");
				finish_game(m);
			}
			m->map[m->player_y - 1][m->player_x] = 'X';
			m->map[m->player_y][m->player_x] = '0';
		}
		else
		{
			collect_coins(m, m->player_y - 1, m->player_x);
			if (m->map[m->player_y][m->player_x] != 'X')
				m->map[m->player_y][m->player_x] = '0';
			else
				m->map[m->player_y][m->player_x] = 'E';
			m->map[m->player_y - 1][m->player_x] = 'P';
		}
		m->player_y = m->player_y - 1;
	}
}

void	move_down(t_map *m)
{
	if (m->map[m->player_y + 1][m->player_x] != '1')
	{
		m->move++;
		ft_printf("%d Movements\n", m->move);
		if (m->map[m->player_y + 1][m->player_x] == 'E')
		{
			if (m->coin == 0)
			{
				ft_printf("FINISH!\n");
				finish_game(m);
			}
			m->map[m->player_y + 1][m->player_x] = 'X';
			m->map[m->player_y][m->player_x] = '0';
		}
		else
		{
			collect_coins(m, m->player_y + 1, m->player_x);
			if (m->map[m->player_y][m->player_x] != 'X')
				m->map[m->player_y][m->player_x] = '0';
			else
				m->map[m->player_y][m->player_x] = 'E';
			m->map[m->player_y + 1][m->player_x] = 'P';
		}
		m->player_y = m->player_y + 1;
	}
}

void	move_right(t_map *m)
{
	if (m->map[m->player_y][m->player_x + 1] != '1')
	{
		m->move++;
		ft_printf("%d Movements\n", m->move);
		if (m->map[m->player_y][m->player_x + 1] == 'E')
		{
			if (m->coin == 0)
			{
				ft_printf("FINISH!\n");
				finish_game(m);
			}
			m->map[m->player_y][m->player_x + 1] = 'X';
			m->map[m->player_y][m->player_x] = '0';
		}
		else
		{
			collect_coins(m, m->player_y, m->player_x + 1);
			if (m->map[m->player_y][m->player_x] != 'X')
				m->map[m->player_y][m->player_x] = '0';
			else
				m->map[m->player_y][m->player_x] = 'E';
			m->map[m->player_y][m->player_x + 1] = 'P';
		}
		m->player_x = m->player_x + 1;
	}
}

void	move_left(t_map *m)
{
	if (m->map[m->player_y][m->player_x - 1] != '1')
	{
		m->move++;
		ft_printf("%d Movements\n", m->move);
		if (m->map[m->player_y][m->player_x - 1] == 'E')
		{
			if (m->coin == 0)
			{
				ft_printf("FINISH!\n");
				finish_game(m);
			}
			m->map[m->player_y][m->player_x - 1] = 'X';
			m->map[m->player_y][m->player_x] = '0';
		}
		else
		{
			collect_coins(m, m->player_y, m->player_x - 1);
			if (m->map[m->player_y][m->player_x] != 'X')
				m->map[m->player_y][m->player_x] = '0';
			else
				m->map[m->player_y][m->player_x] = 'E';
			m->map[m->player_y][m->player_x - 1] = 'P';
		}
		m->player_x = m->player_x - 1;
	}
}
