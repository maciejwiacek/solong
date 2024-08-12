/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_rectangular.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:33:03 by mbaj              #+#    #+#             */
/*   Updated: 2024/07/30 21:09:12 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_if_rectangular(char **map)
{
	int	len;
	int	i;
	
	i = 0;
	len = len_without_newline(map[i]);
	while (map[i])
	{
		if (len_without_newline(map[i]) != len)
			return (false);
	}
	return (true);
}
