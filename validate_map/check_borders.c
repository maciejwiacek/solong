/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:53:55 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 02:27:20 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_borders(char **map)
{
	int		x;
	int		y;
	size_t	height;
	size_t	width;

	height = map_height(map);
	width = map_width(map[0]);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[0][x] != '1' || map[height - 1][x] != '1'
				|| map[y][0] != '1' || map[y][width - 1] != '1')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
