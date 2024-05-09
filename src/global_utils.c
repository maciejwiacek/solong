/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/09 08:55:57 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char **map, char *msg)
{
	int	i;

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
