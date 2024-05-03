#include "../includes/so_long.h"
#include <stdio.h>

int  main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
		error("Wrong number of arguments.");
	map = NULL;
	parse_map(argv[1], &map);
	validate_map(map);
	return 0;
}