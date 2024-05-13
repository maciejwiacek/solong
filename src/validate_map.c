/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:29:55 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/13 14:36:24 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	has_collectibles(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	check_for_start(char **map)
{
	size_t	i;
	size_t	j;
	size_t	starts;

	i = 0;
	starts = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				starts++;
			j++;
		}
		i++;
	}
	if (starts != 1)
		return (false);
	return (true);
}

static bool	check_for_exit(char **map)
{
	size_t	i;
	size_t	j;
	size_t	exits;

	i = 0;
	exits = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exits++;
			j++;
		}
		i++;
	}
	if (exits != 1)
		return (false);
	return (true);
}

static bool	is_rectangular(char **map)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = len_no_newline(map[i]);
	while (map[i])
	{
		if (len_no_newline(map[i]) != len)
			return (false);
		i++;
	}
	return (true);
}

void	validate_map(char **map)
{
	if (!check_for_exit(map))
		error(map, "Wrong number of exits.");
	if (!check_for_start(map))
		error(map, "Wrong number of starts.");
	if (!has_collectibles(map))
		error(map, "Map has zero collectibles.");
	if (!is_rectangular(map))
		error(map, "Map is not rectangular.");
	if (!check_for_chars(map))
		error(map, "Map contains invalid characters.");
	if (!is_closed(map))
		error(map, "Map is not closed.");
	if (!is_finishable(map))
		error(map, "Map is not finishable.");
}
