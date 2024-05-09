/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/08 14:37:32 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**map;
	size_t	i;

	if (argc != 2)
		error(NULL, "Wrong number of arguments.");
	map = parse_map(argv[1]);
	validate_map(map);
	i = 0;
	render_map(map);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
