/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:04:14 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/02 14:15:55 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_duplicate(char **map)
{
	char	**map_cpy;
	size_t	height;
	int	i;
	
	
	height = map_height(map);
	map_cpy = malloc(sizeof(char **) * (height + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			while (i--)
				free(map_cpy[i]);
			free(map_cpy);
			return (NULL);
		}
		i++;
	}
	return (map_cpy);
}


