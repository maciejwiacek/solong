#include "./so_long.h"
#include <stdio.h>

int main(void) {
  int fd = open("map.ber", O_RDONLY);
  t_list *head = NULL;
  char *str;
  while (str = get_next_line(fd))
    ft_lstadd_back(&head, ft_lstnew(str));
  while (head->next) {
    printf("%s", head->content);
    head = head->next;
  }
  close(fd);
  return 0;
}