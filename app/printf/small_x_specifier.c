/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_x_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:43:09 by mbaj              #+#    #+#             */
/*   Updated: 2024/05/02 23:43:39 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	small_x_specifier(unsigned int c)
{
	int		len;
	char	*small_hex;

	len = 0;
	small_hex = "0123456789abcdef";
	if (c > 15)
	{
		len += small_x_specifier(c / 16);
	}
	len += ft_putchar(small_hex[c % 16]);
	return (len);
}
