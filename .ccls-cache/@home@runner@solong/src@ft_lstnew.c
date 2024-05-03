#include "../includes/so_long.h"

t_map	*ft_lstnew(char *str) {
	t_map *new_item;

	new_item = malloc(sizeof(t_map));
	if (new_item == NULL)
		return (NULL);
	new_item->content = ft_strdup(str);
	new_item->next = NULL;
	return (new_item);
}