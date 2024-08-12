/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:16:52 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/01 10:16:54 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] != (char)c)
			i--;
		else
			return ((char *)(s + i));
	}
	return (NULL);
}
/*{
	unsigned char	*p;
	int		i;
	int		index;

	index = -1;
	p = (unsigned char *)s;
	i = 0;
	if (c == '\0')
	{
		p += ft_strlen((const char *)p);
		return ((char *)p);
	}
	while (p[i] != '\0')
	{
		if (p[i] == c)
		{
			index = i;
		}
		i++;
	}
	if (index == -1)
		return (NULL);
	return ((char *)&p[index]);
}*/
/*
int	main(void)
{
	int	a;
	char	k[] = "hla ma koalę";

		a = 'h';
		
	printf("%s", ft_strrchr(k, a));
	return (0);
}*/
