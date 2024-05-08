/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/08 09:49:52 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**map;
	size_t	i;

	if (argc != 2)
		error("Wrong number of arguments.");
	map = parse_map(argv[1]);
	validate_map(map);
	ft_printf("Map parsed successfully\n");
	i = 0;
	ft_printf("Map contains %d collectibles\n", count_collectibles(map));
	while (map[i])
		printf("%s\n", map[i++]);
	while (i-- > 0)
		free(map[i]);
	void *mlx = mlx_init();
	void *mlx_window = mlx_new_window(mlx, 600, 600, "Test");
	mlx_loop(mlx);
	free(map);
	return (0);
}
