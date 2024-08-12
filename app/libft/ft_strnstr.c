/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:12:12 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/01 12:12:15 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*b;
	char			*l;
	unsigned int	i;
	unsigned int	j;

	b = (char *) big;
	l = (char *) little;
	i = 0;
	if (big == NULL && len == 0)
		return (NULL);
	if (*little == '\0')
		return (b);
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && l[j] && (i + j) < len)
			j++;
		if (l[j] == '\0')
			return (&b[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	x[] = "krowa pije wode";
	char	y[] = "pije";
	printf("%s", ft_strnstr(x, y, 11));
	return(0);
}*/
