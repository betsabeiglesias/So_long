/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:06:29 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/10 10:24:10 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charge_window(t_map *m)
{
	m->mlx = mlx_init();
	m->img_width = 50;
	m->img_height = 50;
	m->window = mlx_new_window(m->mlx, m->img_width * m->x,
			m->y * m->img_height, "SO_LONG");
	m->tree = mlx_xpm_file_to_image(m->mlx, "./textures/tree.xpm",
			&m->img_width, &m->img_height);
	m->pig = mlx_xpm_file_to_image(m->mlx, "./textures/pig.xpm",
			&m->img_width, &m->img_height);
	m->bellota = mlx_xpm_file_to_image(m->mlx, "./textures/bellota.xpm",
			&m->img_width, &m->img_height);
	m->grass = mlx_xpm_file_to_image(m->mlx, "./textures/grass.xpm",
			&m->img_width, &m->img_height);
	m->door = mlx_xpm_file_to_image(m->mlx, "./textures/door.xpm",
			&m->img_width, &m->img_height);
	render_window(m);
}

void	put_image(t_map *m, int x, int y)
{
	if (m->map[y][x] == '0')
		mlx_put_image_to_window(m->mlx, m->window, m->grass,
			(x * 50), (y * 50));
	else if (m->map[y][x] == '1')
		mlx_put_image_to_window(m->mlx, m->window, m->tree,
			(x * 50), (y * 50));
	else if (m->map[y][x] == 'C')
		mlx_put_image_to_window(m->mlx, m->window, m->bellota,
			(x * 50), (y * 50));
	else if (m->map[y][x] == 'P')
		mlx_put_image_to_window(m->mlx, m->window, m->pig,
			(x * 50), (y * 50));
	else if (m->map[y][x] == 'E')
		mlx_put_image_to_window(m->mlx, m->window, m->door,
			(x * 50), (y * 50));
	else if (m->map[y][x] == 'X')
	{
		mlx_put_image_to_window(m->mlx, m->window, m->door,
			(x * 50), (y * 50));
		mlx_put_image_to_window(m->mlx, m->window, m->pig,
			(x * 50), (y * 50));
	}
}

void	render_window(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map[y] != 0)
	{
		x = 0;
		while (m->map[y][x] != 0)
		{
			put_image(m, x, y);
			x++;
		}
		y++;
	}
}

void	destroy_window(t_map *m)
{
	mlx_destroy_window(m->mlx, m->window);
	mlx_destroy_image(m->mlx, m->pig);
	mlx_destroy_image(m->mlx, m->bellota);
	mlx_destroy_image(m->mlx, m->door);
	mlx_destroy_image(m->mlx, m->grass);
	mlx_destroy_image(m->mlx, m->tree);
	free_map(m);
}
