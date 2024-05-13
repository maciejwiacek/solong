/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:02:55 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/13 14:03:17 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_num(t_mlx mlx, t_txt txt, int num, int *pos)
{
	if (num == 0)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s0, pos[1], pos[0]);
	if (num == 1)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s1, pos[1], pos[0]);
	if (num == 2)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s2, pos[1], pos[0]);
	if (num == 3)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s3, pos[1], pos[0]);
	if (num == 4)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s4, pos[1], pos[0]);
	if (num == 5)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s5, pos[1], pos[0]);
	if (num == 6)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s6, pos[1], pos[0]);
	if (num == 7)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s7, pos[1], pos[0]);
	if (num == 8)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s8, pos[1], pos[0]);
	if (num == 9)
		mlx_put_image_to_window(mlx.m, mlx.w, txt.s9, pos[1], pos[0]);
}

void	render_score(t_mlx mlx, t_txt txt)
{
	int	pos[2];
	int	num;

	pos[0] = 0;
	pos[1] = 100;
	num = mlx.moves;
	while (pos[1] >= 0)
	{
		render_num(mlx, txt, num % 10, pos);
		num /= 10;
		pos[1] -= 50;
	}
}

void	render_player(t_mlx mlx, t_txt txt, char direction, const int *pos)
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

void	render_tile(t_mlx mlx, t_txt txt, int *pos, char c)
{
	if (c == '1')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.w, pos[1] * 50, pos[0] * 50);
	if (c == '0')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.b, pos[1] * 50, pos[0] * 50);
	if (c == 'C')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.c, pos[1] * 50, pos[0] * 50);
	if (c == 'E')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.e, pos[1] * 50, pos[0] * 50);
	if (c == 'X')
		mlx_put_image_to_window(mlx.m, mlx.w, txt.x, pos[1] * 50, pos[0] * 50);
}
