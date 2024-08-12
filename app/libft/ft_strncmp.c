/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:02:17 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/28 16:13:06 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*k1;
	unsigned char	*k2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	k1 = (unsigned char *) s1;
	k2 = (unsigned char *) s2;
	while (n > 0 && (*k1 != '\0' || *k2 != '\0'))
	{
		if (*k1 != *k2)
			return (*k1 - *k2);
		n--;
		k1++;
		k2++;
	}
	return (0);
}
/*
int	main(void)
{
	char	x[] = "Koala";
	char	y[] = "okt";
	printf("%d", ft_strncmp(x, y, 3));
	return (0);
}*/
