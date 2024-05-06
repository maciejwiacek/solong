/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:33:16 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/06 15:11:46 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_coords(char **map, char c, int *coords)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				coords[0] = x;
				coords[1] = y;
				return ;
			}
			x++;
		}
		y++;
	}
	coords[0] = -1;
	coords[1] = -1;
}

void	flood_fill(char **map, int height, int y, int x)
{
	int	width;

	width = len_no_newline(map[0]);
	if (y < 0 || y >= height || x < 0 || x >= width
		|| map[y][x] == '1' || map[y][x] == 'V')
	{
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, height, y - 1, x);
	flood_fill(map, height, y + 1, x);
	flood_fill(map, height, y, x - 1);
	flood_fill(map, height, y, x + 1);
}

bool	is_all_collected(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
