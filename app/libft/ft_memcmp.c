/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:46:09 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/27 08:24:17 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*k1;
	unsigned char	*k2;
	size_t			i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	k1 = (unsigned char *) s1;
	k2 = (unsigned char *) s2;
	while (i < n)
	{
		if (k1[i] != k2[i])
			return (k1[i] - k2[i]);
		i++;
	}
	return (0);
}
/*
int main ()
{
	char	x1[] = "AlA ma ";
	char	x2[] = "Ala ma Kota";
	size_t	a = 15;
	printf("%d", ft_memcmp(x1, x2, a));
	return (0);
}*/
