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

static bool	has_other_char(char *s, char c)
{
	while (*s && *s != '\n')
	{
		if (*s != c)
			return (true);
		s++;
	}
	return (false);
}

bool	is_closed(t_map *map)
{
	t_map	*cur;
	size_t	len;

	cur = map;
	len = len_no_newline(cur->content);
	if (has_other_char(cur->content, '1'))
		return (false);
	while (cur)
	{
		if ((cur->content)[0] != '1' || (cur->content)[len - 1] != '1')
			return (false);
		cur = cur->next;
	}
	if (has_other_char(cur->content, '1'))
		return (false);
	return (true);
}