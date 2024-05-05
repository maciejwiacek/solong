/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/04 10:32:09 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_for_start(char **map)
{
	size_t	i;
	size_t	j;
	size_t	starts;

	i = 0;
	j = 0;
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
	j = 0;
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
		error("Wrong number of exits.");
	if (!check_for_start(map))
		error("Wrong number of starts.");
	if (!is_rectangular(map))
		error("Map is not rectangular.");
	if (!check_for_chars(map))
		error("Map contains invalid characters.");
	if (!is_closed(map))
		error("Map is not closed.");
	if (!is_finishable(map))
		error("Map is not finishable.");
}
