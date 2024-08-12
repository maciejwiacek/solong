/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:46:06 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/23 17:57:40 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*k;

	i = 0;
	k = (unsigned char *)s;
	while (i < n)
	{
		if (k[i] == (unsigned char) c)
			return (&k[i]);
		i++;
	}
	return (NULL);
}
/*

while (n)
{
	if (*k == c)
		return (k);
	k++;
	n--;
}*/
/*
int	main (void)
{
	char	x[] = "Kocham Placki";
	size_t	a = 20;
	int	d = 'l';
	//ft_memchr(x, d, a);
	printf("%s", (char*) ft_memchr(x, d, a));
	return (0);
}*/
