/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:40:55 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/01 12:49:30 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E'
					&& map[i][j] != 'C' && map[i][j] != 'X'
					&& map[i][j] != '0' && map[i][j] != '1')
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}
