/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 02:27:50 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 01:40:45 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	width = map_width(map[0]);
	if (y < 0 || y >= height || x < 0 || x >= width || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'X')
		return ;
	map[y][x] = 'V';
	flood_fill(map, height, y - 1, x);
	flood_fill(map, height, y + 1, x);
	flood_fill(map, height, y, x - 1);
	flood_fill(map, height, y, x + 1);
}

bool	is_all_collected(char **map)
{
	size_t j;
	size_t i;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}