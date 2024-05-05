/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/04 10:33:15 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc != 2)
		error("Wrong number of arguments.");
	map = parse_map(argv[1]);
	// validate_map(map);
	for (int i = 0; map[i]; i++)
		{
			ft_printf("Line: %s\n", map[i]);
		}
	ft_printf("Map parsed succsefully\n");
	// ft_printf("Map has %d collectibles\n", count_collectibles(map));
	return (0);
}
