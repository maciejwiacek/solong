/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:22:40 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/09 11:40:06 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_mlx *mlx)
{
	if (mlx->map[0][mlx->p_pos[1] - 1][mlx->p_pos[0]] == '1')
		return ;
	if (mlx->p_pos[1] - 1 == mlx->e_pos[1] && mlx->p_pos[0] == mlx->e_pos[0]
		&& is_finished(mlx->map[0]))
	{
		ft_printf("Moves: %d\n", mlx->moves + 1);
		close_window(mlx);
	}
	if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
	else
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
	mlx->map[0][mlx->p_pos[1] - 1][mlx->p_pos[0]] = 'P';
	mlx->p_pos[1]--;
	render_handling(mlx[0], mlx->map[0], mlx->txt);
	mlx->moves++;
}

void	move_down(t_mlx *mlx)
{
	if (mlx->map[0][mlx->p_pos[1] + 1][mlx->p_pos[0]] == '1')
		return ;
	if (mlx->p_pos[1] + 1 == mlx->e_pos[1] && mlx->p_pos[0] == mlx->e_pos[0]
		&& is_finished(mlx->map[0]))
	{
		ft_printf("Moves: %d\n", mlx->moves + 1);
		close_window(mlx);
	}
	if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
	else
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
	mlx->map[0][mlx->p_pos[1] + 1][mlx->p_pos[0]] = 'P';
	mlx->p_pos[1]++;
	render_handling(mlx[0], mlx->map[0], mlx->txt);
	mlx->moves++;
}

void	move_left(t_mlx *mlx)
{
	if (mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] - 1] == '1')
		return ;
	if (mlx->p_pos[1] == mlx->e_pos[1] && mlx->p_pos[0] - 1 == mlx->e_pos[0]
		&& is_finished(mlx->map[0]))
	{
		ft_printf("Moves: %d\n", mlx->moves + 1);
		close_window(mlx);
	}
	if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
	else
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
	mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] - 1] = 'P';
	mlx->p_pos[0]--;
	render_handling(mlx[0], mlx->map[0], mlx->txt);
	mlx->moves++;
}

void	move_right(t_mlx *mlx)
{
	if (mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] + 1] == '1')
		return ;
	if (mlx->p_pos[1] == mlx->e_pos[1] && mlx->p_pos[0] + 1 == mlx->e_pos[0]
		&& is_finished(mlx->map[0]))
	{
		ft_printf("Moves: %d\n", mlx->moves + 1);
		close_window(mlx);
	}
	if (mlx->p_pos[0] == mlx->e_pos[0] && mlx->p_pos[1] == mlx->e_pos[1])
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = 'E';
	else
		mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0]] = '0';
	mlx->map[0][mlx->p_pos[1]][mlx->p_pos[0] + 1] = 'P';
	mlx->p_pos[0]++;
	render_handling(mlx[0], mlx->map[0], mlx->txt);
	mlx->moves++;
}
