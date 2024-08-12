/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_x_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:44:07 by mbaj              #+#    #+#             */
/*   Updated: 2024/05/02 23:43:45 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	large_x_specifier(unsigned int c)
{
	int		len;
	char	*large_hex;

	len = 0;
	large_hex = "0123456789ABCDEF";
	if (c > 15)
	{
		len += large_x_specifier(c / 16);
	}
	len += ft_putchar(large_hex[c % 16]);
	return (len);
}
