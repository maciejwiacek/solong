/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/06 00:40:41 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../app/includes/get_next_line.h"
# include "../app/includes/libft.h"
# include "../app/includes/printf.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_map
{
	char	**board;
	int		*e;
}	t_map;

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
bool	is_finishable(char **map);
size_t	count_collectibles(char **map);

#endif