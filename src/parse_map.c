/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/06 00:39:39 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**parse_map(char *map_path)
{
	int		fd;
	char	**result;
	char	*line;
	char	*str;
	char	*tmp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error("Wrong map path");
	line = get_next_line(fd);
	if (!line)
		error("Map file is empty.");
	str = NULL;
	while (line)
	{
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(tmp, line);
		line = get_next_line(fd);
		free(tmp);
	}
	result = ft_split(str, '\n');
	free(str);
	return (result);
}
