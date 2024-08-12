/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:30:48 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/02 13:30:51 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	z;
	int	r;

	r = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	z = 1;
	if (*nptr == '-')
	{
		z = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		r = r * 10 + (*nptr - '0');
		nptr++;
	}
	r *= z;
	return (r);
}
/*
int	main(void)
{
	const char	a[] = "p469 0\n";
	
	printf("%d", ft_atoi(a));
	return (0);
}
*/
