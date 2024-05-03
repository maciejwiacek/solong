#ifndef SO_LONG
#define SO_LONG

typedef struct s_map {
	char *content;
	struct s_map *next;
} t_map;

#include "../app/includes/get_next_line.h"
#include "../app/includes/libft.h"
#include "../app/includes/printf.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

t_map  *ft_lstnew(char *str);
void    ft_lstadd_back(t_map **lst, t_map *new_list);
void    error(char *msg);
void	parse_map(char *map_path, t_map **map);
void	validate_map(t_map *map);
bool	check_for_chars(t_map *map);
int		len_no_newline(char *s);
bool	is_closed(t_map *map);

#endif