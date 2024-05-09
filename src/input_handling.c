/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:19:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/09 11:40:42 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->m, mlx->w);
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
	return (0);
}
