#include "../includes/so_long.h"

void  ft_lstadd_back(t_map **lst, t_map *new_list) {
	t_map  *cur;

	if (!lst || !new_list)
		return;
	if (*lst == NULL) {
		*lst = new_list;
		return;
	}
	cur = *lst;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_list;
}