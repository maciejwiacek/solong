/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/12 21:49:36 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_player(t_mlx mlx, t_txt txt, char direction, const int *pos)
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
			if (map[pos[0]][pos[1]] == 'X')
				mlx_put_image_to_window(mlx.m, mlx.w, txt.x, pos[1] * 50, pos[0] * 50);
			pos[1]++;
		}
		pos[0]++;
	}
}

void	start_game(char ***map)
{
	t_mlx	mlx;
	t_txt	txt;

	struct_init(map, &mlx, &txt);
	render_handling(mlx, *map, txt, 'r');
	mlx_hook(mlx.w, 17, 0, &close_window, &mlx);
	mlx_key_hook(mlx.w, input_handling, &mlx);
	mlx_loop(mlx.m);
}
