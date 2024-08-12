/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:52:49 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 10:09:36 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_textures(t_game *game)
{
	game->txt.c = mlx_xpm_file_to_image(game->mlx, "textures/texturesC.xpm",
			&(game->w), &(game->h));
	game->txt.z = mlx_xpm_file_to_image(game->mlx, "textures/textures0.xpm",
			&(game->w), &(game->h));
	game->txt.w = mlx_xpm_file_to_image(game->mlx, "textures/textures1.xpm",
			&(game->w), &(game->h));
	game->txt.e = mlx_xpm_file_to_image(game->mlx, "textures/texturesE.xpm",
			&(game->w), &(game->h));
	game->txt.p = mlx_xpm_file_to_image(game->mlx, "textures/texturesP.xpm",
			&(game->w), &(game->h));
}

int	key_handeler(int keycode, t_game *game)
{
	if (keycode == 'w')
		move_player(game, -1, 0, 'w');
	if (keycode == 's')
		move_player(game, 1, 0, 's');
	if (keycode == 'a')
		move_player(game, 0, -1, 'a');
	if (keycode == 'd')
		move_player(game, 0, 1, 'd');
	ft_printf("Moves :%d\n", game->game_counter);
	if (keycode == 65307)
		close_game(game);
	return (0);
}

void	*start_game(t_game game)
{
	game.mlx = mlx_init();
	game.h = map_height(game.map);
	game.w = map_width(game.map[0]);
	game.win = mlx_new_window(game.mlx, game.w * 50, game.h * 50, "so_long");
	find_coords(game.map, 'P', game.p_pos);
	find_coords(game.map, 'E', game.e_pos);
	init_textures(&game);
	fill_textures(game, 'w');
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, key_handeler, &game);
	game.game_counter = 0;
	mlx_loop(game.mlx);
	return (NULL);
}