/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/11 18:23:03 by mwiacek          ###   ########.fr       */
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

static void	render_player(t_mlx mlx, t_txt txt, char direction, int *pos)
{
	if (direction == 'u')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.u, pos[1] * 50, pos[0] * 50);
	if (direction == 'd')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.d, pos[1] * 50, pos[0] * 50);
	if (direction == 'l')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.l, pos[1] * 50, pos[0] * 50);
	if (direction == 'r')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.r, pos[1] * 50, pos[0] * 50);
}

void	render_handling(t_mlx mlx, char **map, t_txt txt, char direction)
{
	int pos[2];

	pos[0] = 0;
	while (map[pos[0]])
	{
		pos[1] = 0;
		while (map[pos[0]][pos[1]])
		{
			if (map[pos[0]][pos[1]] == '1')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.w, pos[1] * 50, pos[0] * 50);
			if (map[pos[0]][pos[1]] == '0')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.b, pos[1] * 50, pos[0] * 50);
			if (map[pos[0]][pos[1]] == 'C')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.c, pos[1] * 50, pos[0] * 50);
			if (map[pos[0]][pos[1]] == 'P')
				render_player(mlx, txt, direction, pos);
			if (map[pos[0]][pos[1]] == 'E')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.e, pos[1] * 50, pos[0] * 50);
			pos[1]++;
		}
		pos[0]++;
	}
}

void	start_game(char ***map)
{
	t_mlx	mlx;
	t_txt	txt;
	int		height;
	int		width;

	height = calculate_map_height(*map);
	width = len_no_newline(map[0][0]);
	mlx.m = mlx_init();
	mlx.w = mlx_new_window(mlx.m, width * 50, height * 50, "so_long");
	mlx.map = map;
	find_coords(*map, 'P', mlx.p_pos);
	find_coords(*map, 'E', mlx.e_pos);
	init_textures(&mlx, &txt);
	mlx.moves = 0;
	render_handling(mlx, *map, txt, 'r');
	mlx_hook(mlx.w, 17, 0, &close_window, &mlx);
	mlx_key_hook(mlx.w, input_handling, &mlx);
	mlx_loop(mlx.m);
}
