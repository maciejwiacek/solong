/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:17:48 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/04 10:31:51 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../app/includes/get_next_line.h"
#include "../app/includes/libft.h"
#include "../app/includes/printf.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_map {
  char *content;
  struct s_map *next;
} t_map;

t_map *ft_lstnew(char *str);
void ft_lstadd_back(t_map **lst, t_map *new_list);
void error(char *msg);
char **parse_map(char *map_path);
void validate_map(t_map *map);
bool check_for_chars(t_map *map);
int len_no_newline(char *s);
bool is_closed(t_map *map);

#endif