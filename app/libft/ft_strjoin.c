/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:52:29 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/28 16:52:25 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	len_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen((char *)s1);
	s = (char *)malloc((len_s1 + ft_strlen((char *)s2) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (i < len_s1)
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen((char *)s2))
	{
		s[len_s1 + i] = s2[i];
		i++;
	}
	s[len_s1 + ft_strlen((char *)s2)] = '\0';
	return (s);
}
/*
int	main(void)
{
	char *	k1 = "Ala ma ";
	char *	k2 = "kota";
	printf("%s", ft_strjoin(k1, k2));
	return (0);
}*/	
