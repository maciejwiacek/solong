/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:26:12 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/12 21:31:16 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_textures(t_mlx *mlx, t_txt *txt)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	txt->b = mlx_xpm_file_to_image(mlx->m, "./textures/b.xpm", &w, &h);
	txt->c = mlx_xpm_file_to_image(mlx->m, "./textures/c.xpm", &w, &h);
	txt->e = mlx_xpm_file_to_image(mlx->m, "./textures/e.xpm", &w, &h);
	txt->w = mlx_xpm_file_to_image(mlx->m, "./textures/w.xpm", &w, &h);
	txt->u = mlx_xpm_file_to_image(mlx->m, "./textures/u.xpm", &w, &h);
	txt->d = mlx_xpm_file_to_image(mlx->m, "./textures/d.xpm", &w, &h);
	txt->l = mlx_xpm_file_to_image(mlx->m, "./textures/l.xpm", &w, &h);
	txt->r = mlx_xpm_file_to_image(mlx->m, "./textures/r.xpm", &w, &h);
	txt->x = mlx_xpm_file_to_image(mlx->m, "./textures/x.xpm", &w, &h);
	mlx->txt = *txt;
}

static int	calculate_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	struct_init(char ***map, t_mlx *mlx, t_txt *txt)
{
	int	height;
	int	width;

	height = calculate_map_height(*map);
	width = len_no_newline(map[0][0]);
	mlx->m = mlx_init();
	mlx->w = mlx_new_window(mlx->m, width * 50, height * 50, "so_long");
	mlx->map = map;
	mlx->moves = 0;
	find_coords(*map, 'P', mlx->p_pos);
	find_coords(*map, 'E', mlx->e_pos);
	init_textures(mlx, txt);
}