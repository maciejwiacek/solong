/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:54:55 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 02:31:29 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char **map, char *msg)
{
	int i;

	i = 0;
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	if (map && map[0])
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	exit(1);
}