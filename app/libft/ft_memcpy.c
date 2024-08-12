/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:20:55 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/28 16:07:28 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	unsigned char	*s;
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = (unsigned char *)src;
	d = (char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
int	main(void)
{
	char	x[] = " ";
	char	y[20];
	size_t	a = 4;
	ft_memcpy(y, x, a);
	printf("%s", y);
	return (0);
}
*/