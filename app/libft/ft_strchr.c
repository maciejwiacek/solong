/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:28:05 by mbaj              #+#    #+#             */
/*   Updated: 2024/02/29 19:28:08 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char)c)
			i++;
		else
			return ((char *)(s + i));
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*{
	unsigned char	*p;

	p = (unsigned char *)s;
	if (c == '\0')
	{
		p += ft_strlen((const char *)p);
		return ((char *)p);
	}
	while (*p != '\0')
	{
		if (*p == (char)c)
		{
			return ((char *)p);
		}
	}
	return (NULL);
}*/
/*
int	main(void)
{
	int	a;
	char	k[] = "Ala ma kota";

		a = 'm';
		
	printf("%s", ft_strchr(k, a));
	return (0);
}*/	
