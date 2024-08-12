/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:23:39 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 00:26:19 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_texture(t_game game, void *txt, short x, short y)
{
	mlx_put_image_to_window(game.mlx, game.win, txt, x, y);
}

static void	fill_player_textures(t_game game, char key, short x, short y)
{
	if (key == 'w' || key == 's' || key == 'a' || key == 'd')
		fill_texture(game, game.txt.p, x, y);
}

void	fill_textures(t_game game, char key)
{
	short	i;
	short	j;

	i = -1;
	while (++i, game.map[i])
	{
		j = -1;
		while (++j, game.map[i][j])
		{
			if (game.map[i][j] == '0')
				fill_texture(game, game.txt.z, j * 50, i * 50);
			if (game.map[i][j] == '1')
				fill_texture(game, game.txt.w, j * 50, i * 50);
			if (game.map[i][j] == 'C')
				fill_texture(game, game.txt.c, j * 50, i * 50);
			if (game.map[i][j] == 'P')
				fill_player_textures(game, key, j * 50, i * 50);
			if (game.map[i][j] == 'E')
				fill_texture(game, game.txt.e, j * 50, i * 50);
		}
	}
}