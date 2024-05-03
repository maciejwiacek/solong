#include "../includes/so_long.h"

void	parse_map(char *map_path, t_map **map)
{
	int		fd;
	char	*str;
	t_map	*new;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error("Wrong map path");
	str = get_next_line(fd);
	while (str)
	{
		new = ft_lstnew(str);
		ft_lstadd_back(map, new);
		str = get_next_line(fd);
	}
	free(str);
}