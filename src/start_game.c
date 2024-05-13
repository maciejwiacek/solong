/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/13 14:02:52 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_handling(t_mlx mlx, char **map, t_txt txt, char direction)
{
	int	p[2];

	p[0] = 0;
	while (map[p[0]])
	{
		p[1] = 0;
		while (map[p[0]][p[1]])
		{
			if (map[p[0]][p[1]] == '1')
				render_tile(mlx, txt, p, '1');
			if (map[p[0]][p[1]] == '0')
				render_tile(mlx, txt, p, '0');
			if (map[p[0]][p[1]] == 'C')
				render_tile(mlx, txt, p, 'C');
			if (map[p[0]][p[1]] == 'P')
				render_player(mlx, txt, direction, p);
			if (map[p[0]][p[1]] == 'E')
				render_tile(mlx, txt, p, 'E');
			if (map[p[0]][p[1]] == 'X')
				render_tile(mlx, txt, p, 'X');
			p[1]++;
		}
		p[0]++;
	}
	render_score(mlx, txt);
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
