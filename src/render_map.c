/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/08 13:11:21 by mwiacek          ###   ########.fr       */
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
	textures->exit = mlx_xpm_file_to_image(mlx.mlx, "./textures/collectible.xpm", &width, &height);
	textures->player = mlx_xpm_file_to_image(mlx.mlx, "./textures/pl.xpm", &width, &height);
	textures->wall = mlx_xpm_file_to_image(mlx.mlx, "./textures/wall.xpm", &width, &height);
}

// TODO: Player (up, down, left, right); Exit

void	render_map(char **map)
{
	t_mlx		mlx;
	t_textures	textures;

	mlx.mlx = mlx_init();
	mlx.mlx_window = mlx_new_window(mlx.mlx, 600, 600, "so_long");
	mlx_loop(mlx.mlx);
}