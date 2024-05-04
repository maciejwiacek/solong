/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/04 10:34:54 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_lstadd_back(t_map **lst, t_map *new_list)
{
	t_map	*cur;

	if (!lst || !new_list)
		return ;
	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	cur = *lst;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_list;
}
