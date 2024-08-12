/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:55:45 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/12 08:55:45 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "app/get_next_line/get_next_line.h"
# include "app/libft/libft.h"
# include "app/printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*typedef struct	s_point
{
	int x;
	int y;
}  t_point;*/
typedef struct s_txt
{
	void	*c;
	void	*w;
	void	*z;
	void	*e;
	void	*p;
}			t_txt;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int		p_pos[2];
	int		e_pos[2];
	int		game_counter;
	t_txt	txt;
}			t_game;
char		**parsing_map(char *map);
void		flood_fill(char **map, int height, int y, int x);
int			close_game(t_game *game);
int			key_handeler(int keycode, t_game *game);
void		*start_game(t_game game);
void		find_coords(char **map, char c, int *coords);
void		move_player(t_game *game, short x_off, short y_off, char key);
void		fill_textures(t_game game, char key);

void		validate_map(char **map);
bool		check_start(char **map);
bool		check_exit(char **map);
bool		check_if_rectangular(char **map);
bool		check_collectibles(char **map);
bool		check_chars(char **map);
bool		check_borders(char **map);
bool		is_all_collected(char **map);

int			len_without_newline(char *str);
size_t		map_height(char **map);
size_t		map_width(char *s);
void		error(char **map, char *msg);
void		free_map(char **map);

#endif
