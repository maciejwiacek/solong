/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:46:23 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/25 16:03:50 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_handle_wrong_start(void)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 1);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;
	size_t	i;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen(s);
	i = 0;
	if (start >= strlen)
		return (ft_handle_wrong_start());
	if (strlen - start < len)
		len = strlen - start;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (len > i)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
/*
int	main(void)
{
	char const k[] = "Ala ma kota";
	unsigned int st = 4;
	size_t	t = 10;
	
	printf("%s", ft_substr(k, st, t));
	return (0);
}*/
