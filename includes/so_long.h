/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/08 13:07:46 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TRANSPARENT_COLOR
# define TRANSPARENT_COLOR 0xFF0000
# endif
# include "../app/includes/get_next_line.h"
# include "../app/includes/libft.h"
# include "../app/includes/printf.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}	t_mlx;

typedef struct	s_textures
{
	void	*wall;
	void	*bg;
	void	*collect;
	void	*player;
	void	*exit;
}	t_textures;

void	error(char *msg);
char	**parse_map(char *map_path);
void	validate_map(char **map);
bool	check_for_chars(char **map);
int		len_no_newline(char *s);
bool	is_closed(char **map);
void	find_coords(char **map, char c, int coords[2]);
void	flood_fill(char **map, int height, int y, int x);
bool	is_finishable(char **map);
bool	is_all_collected(char **map);
size_t	count_collectibles(char **map);

// MLX
void	render_map(char **map);

#endif