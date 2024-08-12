/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:23:11 by mbaj              #+#    #+#             */
/*   Updated: 2024/05/02 21:24:30 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_specifier(unsigned int number)
{
	int	len;
	int	new_num;

	len = 0;
	new_num = 0;
	if (number == 0)
		return (write(1, "0", 1));
	if (number > 9)
		len += id_specifier(number / 10);
	new_num = (number % 10) + '0';
	len += write(1, &new_num, 1);
	return (len);
}
