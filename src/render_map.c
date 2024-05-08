/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/08 16:10:51 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_textures(t_mlx mlx, t_txt *txt)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	txt->b = mlx_xpm_file_to_image(mlx.m, "./textures/b.xpm", &w, &h);
	txt->c = mlx_xpm_file_to_image(mlx.m, "./textures/c.xpm", &w, &h);
	txt->e = mlx_xpm_file_to_image(mlx.m, "./textures/e.xpm", &w, &h);
	txt->p = mlx_xpm_file_to_image(mlx.m, "./textures/p.xpm", &w, &h);
	txt->w = mlx_xpm_file_to_image(mlx.m, "./textures/w.xpm", &w, &h);
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

static void	render_handling(t_mlx mlx, char **map, t_txt txt)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.w, j * 50, i * 50);
			if (map[i][j] == '0')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.b, j * 50, i * 50);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.c, j * 50, i * 50);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.p, j * 50, i * 50);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.e, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	render_map(char **map)
{
	t_mlx	mlx;
	t_txt	txt;
	int		height;
	int		width;

	height = calculate_map_height(map);
	width = len_no_newline(map[0]);
	mlx.m = mlx_init();
	mlx.w = mlx_new_window(mlx.m, width * 50, height * 50, "so_long");
	init_textures(mlx, &txt);
	render_handling(mlx, map, txt);
	mlx_loop(mlx.m);
}
