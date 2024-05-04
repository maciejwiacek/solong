/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/04 10:33:46 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(1);
}

int	count_collectibles(t_map *map)
{
	t_map	*cur;
	char	*line;
	int		collectibles;

	cur = map;
	collectibles = 0;
	while (cur)
	{
		line = cur->content;
		while (*line)
		{
			if (*line == 'C')
				collectibles++;
			line++;
		}
		cur = cur->next;
	}
	return (collectibles);
}
