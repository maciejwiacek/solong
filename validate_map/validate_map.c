/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:33:53 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 09:01:25 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_map(char **map)
{
	if (!check_exit(map))
		error(map, "There is none or more than one Exit!");
	if (!check_start(map))
		error(map, "There is none or more than one Start!");
	if (!check_collectibles(map))
		error(map, "There is none Collectibles");
	if (!check_if_rectangular(map))
		error(map, "The map is not Rectangular!");
	if (!check_borders(map))
		error(map, "The map is not surranded by walls!");
	if (!check_chars(map))
		error(map, "Found char that is not in the map!");
}
