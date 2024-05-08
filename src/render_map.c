/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/08 13:33:56 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_textures(t_mlx mlx, t_textures *textures)
{
	int	width;
	int height;

	width = 50;
	height = 50;
	textures->bg = mlx_xpm_file_to_image(mlx.mlx, "./textures/bg.xpm", &width, &height);
	textures->collect = mlx_xpm_file_to_image(mlx.mlx, "./textures/collectible.xpm", &width, &height);
	textures->exit = mlx_xpm_file_to_image(mlx.mlx, "./textures/exit.xpm", &width, &height);
	textures->player = mlx_xpm_file_to_image(mlx.mlx, "./textures/player.xpm", &width, &height);
	textures->wall = mlx_xpm_file_to_image(mlx.mlx, "./textures/wall.xpm", &width, &height);
}

// TODO: Player (up, down, left, right);

static int	calculate_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	render_handling(t_mlx mlx, char **map, t_textures textures)
{
	int	i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, textures.wall, j * 50, i * 50);
			if (map[i][j] == '0')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, textures.bg, j * 50, i * 50);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, textures.collect, j * 50, i * 50);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, textures.player, j * 50, i * 50);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, textures.exit, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	render_map(char **map)
{
	t_mlx		mlx;
	t_textures	textures;
	int			height;
	int 		width;

	height = calculate_map_height(map);
	width = len_no_newline(map[0]);
	mlx.mlx = mlx_init();
	mlx.mlx_window = mlx_new_window(mlx.mlx, width * 50, height * 50, "so_long");
	init_textures(mlx, &textures);
	render_handling(mlx, map, textures);
	mlx_loop(mlx.mlx);
}