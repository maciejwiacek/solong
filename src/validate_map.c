#include "../includes/so_long.h"

static bool	check_for_start(t_map *map)
{
	t_map	*cur;
	size_t	i;
	size_t	starts;

	cur = map;
	starts = 0;
	while (cur)
	{
		i = 0;
		while (cur->content[i])
		{
			if (cur->content[i] == 'P')
				starts++;
			i++;
		}
		cur = cur->next;
	}
	if (starts != 1)
		return (false);
	return (true);
}

static bool	check_for_exit(t_map *map)
{
	t_map	*cur;
	size_t	i;
	size_t	exits;

	cur = map;
	exits = 0;
	while (cur)
	{
		i = 0;
		while (cur->content[i])
		{
			if (cur->content[i] == 'E')
				exits++;
			i++;
		}
		cur = cur->next;
	}
	if (exits != 1)
		return (false);
	return (true);
}

static bool	is_rectangular(t_map *map)
{
	t_map	*cur;
	size_t	len;

	cur = map;
	len = len_no_newline(cur->content);
	while (cur)
	{
		if (len_no_newline(cur->content) != len)
			return (false);
		cur = cur->next;
	}
	return (true);
}

void	validate_map(t_map *map)
{
	if (!check_for_exit(map))
		error("Wrong number of exits.");
	if (!check_for_start(map))
		error("Wrong number of starts.");
	if (!is_rectangular(map))
		error("Map is not rectangular.");
	if (!check_for_chars(map))
		error("Map contains invalid characters.");
	if (!is_closed(map))
		error("Map is not closed.");
}