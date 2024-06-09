/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:55:15 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/09 11:48:57 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 5)
		return (-1);
	if (argv[len - 1] != 'r' || argv[len - 2] != 'e' || argv[len - 3] != 'b'
		|| argv[len - 4] != '.')
		return (-1);
	return (len);
}

char	**get_axis(char *argv, t_map *m)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		ft_error("Error\nNo map to read\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nNo line in map\n");
	m->x = ft_strlen(line) - 1;
	m->y = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != m->x)
			ft_error("Error\nIncorrect map form\n");
		m->y++;
		temp = line;
		line = get_next_line(fd);
		free(temp);
	}
	close(fd);
	return (get_map(argv, m));
}

char	**get_map(char *argv, t_map *m)
{
	int		fd_new;
	int		i;
	char	*line;

	fd_new = open(argv, O_RDONLY);
	if (fd_new <= 0)
		ft_error("Error\nNo map to read\n");
	m->map = (char **) malloc(sizeof(char *) * (m->y + 1));
	line = get_next_line(fd_new);
	if (!line)
		ft_error("Error\nNo line in map\n");
	i = 0;
	while (i < m->y)
	{
		m->map[i] = line;
		line = get_next_line(fd_new);
		i++;
	}
	m->map[i] = NULL;
	close(fd_new);
	return (m->map);
}

void	run_game(char *argv, t_map *m)
{
	get_map(argv, m);
	charge_window(m);
	search_player(m);
	mlx_hook(m->window, 2, 0, ft_keyhook, m);
	mlx_hook(m->window, 17, 0, finish_game, m);
	mlx_loop(m->mlx);
}

int	main(int argc, char **argv)
{
	t_map	m;

	m.move = 0;
	if (argc != 2 || check_extension(argv[1]) == -1)
		ft_error("Error\nInvalid Map\n");
	m.map = get_axis(argv[1], &m);
	if (checks(&m) == 0)
		return (0);
	run_game(argv[1], &m);
	return (0);
}
