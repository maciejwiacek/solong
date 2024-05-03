#include "so_long.h"

t_list *ft_lstnew(char *str) {
  t_list *new_item;

  new_item = malloc(sizeof(t_list));
  if (new_item == NULL)
    return (NULL);
  new_item->content = ft_strdup(str);
  new_item->next = NULL;
  return (new_item);
}