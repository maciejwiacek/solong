/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:46:23 by mbaj              #+#    #+#             */
/*   Updated: 2024/05/03 16:27:46 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_specifier(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len += write(1, "%", 1);
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		len += id_specifier(va_arg(args, int));
	if (format == 'x')
		len += small_x_specifier(va_arg(args, unsigned int));
	if (format == 'X')
		len += large_x_specifier(va_arg(args, unsigned int));
	if (format == 'p')
		len += p_specifier(va_arg(args, void *));
	if (format == 'u')
		len += u_specifier(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += s_specifier(args, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
