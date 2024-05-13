/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/13 13:43:49 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TRANSPARENT_COLOR
#  define TRANSPARENT_COLOR 0xFF0000
# endif
# include "../app/includes/get_next_line.h"
# include "../app/includes/libft.h"
# include "../app/includes/printf.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_txt
{
	void	*w;
	void	*b;
	void	*c;
	void	*e;
	void	*u;
	void	*d;
	void	*l;
	void	*r;
	void	*x;
	void	*s0;
	void	*s1;
	void	*s2;
	void	*s3;
	void	*s4;
	void	*s5;
	void	*s6;
	void	*s7;
	void	*s8;
	void	*s9;
}	t_txt;

typedef struct s_mlx
{
	void	*m;
	void	*w;
	char	***map;
	int		p_pos[2];
	int		e_pos[2];
	int		moves;
	t_txt	txt;
}	t_mlx;

void	error(char **map, char *msg);
char	**parse_map(char *map_path);
void	validate_map(char **map);
bool	check_for_chars(char **map);
int		len_no_newline(char *s);
bool	is_closed(char **map);
void	find_coords(char **map, char c, int coords[2]);
void	flood_fill(char **map, int height, int y, int x);
bool	is_finishable(char **map);
bool	is_all_collected(char **map);
bool	is_finished(char **map);

// MLX
void	start_game(char ***map);
void	struct_init(char ***map, t_mlx *mlx, t_txt *txt);
int		input_handling(int keycode, t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	render_handling(t_mlx mlx, char **map, t_txt txt, char direction);

#endif
