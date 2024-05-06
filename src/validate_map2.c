/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/06 15:15:58 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_for_chars(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while ((map)[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != 'C' && map[i][j] != '1'
				&& map[i][j] != '0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	has_other_char(char *s, char c)
{
	while (*s && *s != '\n')
	{
		if (*s != c)
			return (true);
		s++;
	}
	return (false);
}

bool	is_closed(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = len_no_newline(map[i]);
	if (has_other_char(map[i], '1'))
		return (false);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (false);
		i++;
	}
	if (has_other_char(map[i - 1], '1'))
		return (false);
	return (true);
}

static char	**duplicate_map(char **map)
{
	char	**res;
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	res = malloc((i + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[i] = NULL;
	i = 0;
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		if (!res[i])
		{
			while (i--)
				free(res[i]);
			free (res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

bool	is_finishable(char **map)
{
	char	**map_cpy;
	int		p_coords[2];
	size_t	height;
	bool	is_finishable;

	height = 0;
	while (map[height])
		height++;
	map_cpy = duplicate_map(map);
	if (!map_cpy)
		error("Allocation failed.");
	is_finishable = true;
	find_coords(map_cpy, 'P', p_coords);
	flood_fill(map_cpy, height, p_coords[1], p_coords[0]);
	if (!is_all_collected(map_cpy))
		is_finishable = false;
	while (height-- > 0)
	{
		free(map_cpy[height]);
	}
	free(map_cpy);
	return (is_finishable);
}
