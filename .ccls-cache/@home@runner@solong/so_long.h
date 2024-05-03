#ifndef SO_LONG
#define SO_LONG

typedef struct s_list {
  char *content;
  struct s_list *next;
} t_list;

#include "app/includes/get_next_line.h"
#include "app/includes/libft.h"
#include "app/includes/printf.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

t_list *ft_lstnew(char *str);
void ft_lstadd_back(t_list **lst, t_list *new);

#endif