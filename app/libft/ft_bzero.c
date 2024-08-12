/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:53:08 by mbaj              #+#    #+#             */
/*   Updated: 2024/02/29 16:53:15 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*k;

	i = 0;
	k = (unsigned char *)s;
	while (i < n)
	{
		k[i] = 0;
		i++;
	}
}
/*
int main(void)
{
	char	d[] = "majamaja";
	size_t n = 4;
	ft_bzero(d, n);
	printf("%s", d);
	return (0);
}*/
