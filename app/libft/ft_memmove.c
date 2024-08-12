/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:58:38 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/28 17:19:59 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	char			*d;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = (unsigned char *)src;
	d = (char *)dest;
	if (dest <= src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n)
		{
			*d-- = *s--;
			n--;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	x[] = "Ala ma kota";
	char	y[20];
	size_t	a = 8;
	ft_memmove(y, x, a);
	printf("%s", y);
	return (0);
}*/
