/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/09 09:27:53 by mwiacek          ###   ########.fr       */
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

static int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->m, mlx->w);
	exit (0);
}

int	key_handling(int keycode, t_mlx *mlx)
{
	if (keycode == 100 && mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] + 1] != '1') // RIGHT
	{
		if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		{
			if (is_all_collected(mlx->map[0]))
				close_window(mlx);
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
		}
		else
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] + 1] = 'P';
		mlx->p_pos[0]++;
		render_handling(mlx[0], mlx->map[0], mlx->txt);
	}
	if (keycode == 97 && mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] - 1] != '1') // LEFT
	{
		if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		{
			if (is_all_collected(mlx->map[0]))
				close_window(mlx);
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
		}
		else
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] - 1] = 'P';
		mlx->p_pos[0]--;
		render_handling(mlx[0], mlx->map[0], mlx->txt);
	}
	if (keycode == 119 && mlx->map[0][mlx->p_pos[1] - 1][mlx->p_pos[0]] != '1') // UP
	{
		if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		{
			if (is_all_collected(mlx->map[0]))
				close_window(mlx);
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
		}
		else
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
		mlx->map[0][mlx->p_pos[1] - 1][mlx->p_pos[0]] = 'P';
		mlx->p_pos[1]--;
		render_handling(mlx[0], mlx->map[0], mlx->txt);
	}
	if (keycode == 115 && mlx->map[0][mlx->p_pos[1] + 1][mlx->p_pos[0]] != '1') // DOWN
	{
		if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		{
			if (is_all_collected(mlx->map[0]))
				close_window(mlx);
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
		}
		else
			mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
		mlx->map[0][mlx->p_pos[1] + 1][mlx->p_pos[0]] = 'P';
		mlx->p_pos[1]++;
		render_handling(mlx[0], mlx->map[0], mlx->txt);
	}
	return 0;
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
	mlx.map = &map;
	find_coords(map, 'P', mlx.p_pos);
	find_coords(map, 'E', mlx.e_pos);
	init_textures(mlx, &txt);
	mlx.txt = txt;
	render_handling(mlx, map, txt);
	mlx_hook(mlx.w, 17, 0, &close_window, &mlx);
	mlx_key_hook(mlx.w, key_handling, &mlx);
	mlx_loop(mlx.m);
}
