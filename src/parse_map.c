/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/09 07:09:56 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
	{
		result = ft_strdup(s2);
		free(s2);
		return (result);
	}
	if (!s2)
		return (s1);
	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

char	*create_str(int fd)
{
	char	*line;
	char	*str;

	str = NULL;
	line = get_next_line(fd);
	if (!line)
		error(NULL, "Map file is empty.");
	str = ft_strdup("");
	while (line)
	{
		str = ft_strjoin_free(str, line);
		line = get_next_line(fd);
	}
	free(line);
	return (str);
}

char	**parse_map(char *map_path)
{
	int		fd;
	char	*str;
	char	**res;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error(NULL, "Wrong map path");
	str = create_str(fd);
	res = ft_split(str, '\n');
	free(str);
	close(fd);
	return (res);
}
