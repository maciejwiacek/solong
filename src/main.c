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

// int	main(int argc, char *argv[])
// {
// 	char	**map;
// 	int		p_coords[2];
// 	int		collectibles;

// 	if (argc != 2)
// 		error("Wrong number of arguments.");
// 	map = parse_map(argv[1]);
// 	validate_map(map);
// 	find_coords(map, 'P', p_coords);
// 	collectibles = 0;
// 	ft_printf("valid map: %d, collectibles: %d\n", flood_fill(map, p_coords[1], p_coords[0], 0, &collectibles), collectibles);
// 	ft_printf("%d x %d -> coords of p\n", p_coords[0], p_coords[1]);
// 	ft_printf("Map parsed succsefully\n");
// 	// ft_printf("Map has %d collectibles\n", count_collectibles(map));
// 	return (0);
// }

int main(int argc, char *argv[]) {
	char **map;
	int p_coords[2];
	int collectibles = 0;
	int exits = 0;

	if (argc != 2)
		error("Wrong number of arguments.");
	map = parse_map(argv[1]);
	validate_map(map);
	is_finishable(map);
	ft_printf("Map parsed successfully\n");
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	return 0;
}