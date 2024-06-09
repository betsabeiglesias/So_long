/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:51:51 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/13 09:21:13 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "lib/mlx/mlx.h"
# include "lib/ft_printf/ft_printf.h"
# include <stdbool.h>
# define KEY_ESQ 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123 

typedef struct s_map
{
	int		x;
	int		y;
	int		coin_flood;
	int		count;
	bool	exit_flood;
	char	**map;
	int		player;
	int		coin;
	int		exit;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*window;
	void	*tree;
	void	*pig;
	void	*bellota;
	void	*door;
	void	*grass;
	int		player_x;
	int		player_y;
	int		move;
}			t_map;

/* so_long.c */
int		check_extension(char *argv);
char	**get_axis(char *argv, t_map *m);
char	**get_map(char *argv, t_map *m);
void	run_game(char *argv, t_map *m);

/* so_long_checkmap.c */
int		check_wall(t_map *m);
int		count_check_comps(t_map *m);
int		checks(t_map *m);

/* so_long_floodfill.c */
void	search_player(t_map *m);
void	playable(t_map *m, int y, int x);
int		flood_fill(t_map *m);

/* so_long_images.c */
void	charge_window(t_map *m);
void	put_image(t_map *m, int x, int y);
void	render_window(t_map *m);
void	destroy_window(t_map *m);

/* so_long_keys.c */
int		ft_keyhook(int key, t_map *m);
void	move_up(t_map *m);
void	move_down(t_map *m);
void	move_right(t_map *m);
void	move_left(t_map *m);

/* so_long_utils.c */
int		ft_error(char *s);
int		finish_game(t_map *m);
void	collect_coins(t_map *m, int y, int x);
void	free_map(t_map *m);

#endif