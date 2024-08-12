/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:52:37 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 10:01:33 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->txt.c);
	mlx_destroy_image(game->mlx, game->txt.z);
	mlx_destroy_image(game->mlx, game->txt.w);
	mlx_destroy_image(game->mlx, game->txt.e);
	mlx_destroy_image(game->mlx, game->txt.p);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(0);
	return (0);
}
