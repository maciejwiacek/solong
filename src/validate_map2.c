#include "../includes/so_long.h"

bool	check_for_chars(t_map *map)
{
	t_map *cur;
	size_t i;

	cur = map;
	while (cur) {
		i = 0;
		while ((cur->content)[i] && (cur->content)[i] != '\n') {
			if ((cur->content)[i] != 'P' && (cur->content)[i] != 'E'
				&& (cur->content)[i] != 'C' && (cur->content)[i] != '1'
				&& (cur->content)[i] != '0')
				return false;
			i++;
		}
		cur = cur->next;
	}
	return true;
}

bool	is_closed(t_map *map)
{
	t_map	*cur;

	cur = map; 
}