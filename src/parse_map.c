/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/04 10:33:53 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(char *map_path, t_map **map)
{
	int		fd;
	char	*str;
	t_map	*new;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error("Wrong map path");
	str = get_next_line(fd);
	if (!str)
		error("Map file is empty.");
	while (str)
	{
		new = ft_lstnew(str);
		ft_lstadd_back(map, new);
		str = get_next_line(fd);
	}
	free(str);
}
