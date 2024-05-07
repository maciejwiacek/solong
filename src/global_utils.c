/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/04 10:33:46 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(1);
}

size_t	count_collectibles(char **map)
{
	size_t	x;
	size_t	y;
	size_t	collectibles;

	y = 0;
	collectibles = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}