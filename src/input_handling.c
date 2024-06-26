/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:19:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/11 18:00:30 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx_destroy_image(mlx->m, mlx->txt.w);
	mlx_destroy_image(mlx->m, mlx->txt.b);
	mlx_destroy_image(mlx->m, mlx->txt.c);
	mlx_destroy_image(mlx->m, mlx->txt.e);
	mlx_destroy_image(mlx->m, mlx->txt.u);
	mlx_destroy_image(mlx->m, mlx->txt.d);
	mlx_destroy_image(mlx->m, mlx->txt.l);
	mlx_destroy_image(mlx->m, mlx->txt.r);
	mlx_destroy_window(mlx->m, mlx->w);
	mlx_destroy_display(mlx->m);
	free(mlx->m);
	while (mlx->map[0][i])
	{
		free(mlx->map[0][i]);
		i++;
	}
	free(mlx->map[0]);
	exit (0);
}

int	input_handling(int keycode, t_mlx *mlx)
{
	if (keycode == 119 || keycode == 65362)
		move_up(mlx);
	if (keycode == 115 || keycode == 65364)
		move_down(mlx);
	if (keycode == 97 || keycode == 65361)
		move_left(mlx);
	if (keycode == 100 || keycode == 65363)
		move_right(mlx);
	if (keycode == 65307)
		close_window(mlx);
	return (0);
}
