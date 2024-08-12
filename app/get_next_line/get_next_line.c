/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:46:56 by mbaj              #+#    #+#             */
/*   Updated: 2024/05/27 18:42:56 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*read_lines(char *store, char *buffer, int fd)
{
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (store == NULL)
			store = ft_strdup("");
		store = ft_strjoin(store, buffer);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	return (store);
}

char	*process_line(char *line)
{
	int		i;
	char	*store;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	store = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	if (store == NULL)
		return (NULL);
	line[i + 1] = '\0';
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store = NULL;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = read_lines(store, buffer, fd);
	free(buffer);
	if (line == NULL)
		return (NULL);
	store = process_line(line);
	return (line);
}
/*
int main(void)
{
  int fd;
  
  fd = open("./test.txt", O_RDONLY);
  char *line;
  while ((line = get_next_line(fd)))
    printf("Line: %s", line);
}*/
