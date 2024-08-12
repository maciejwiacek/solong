/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:27:13 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/13 18:27:17 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void print_index_value(unsigned int index, char *c)
{
	printf("Character at index %u: %c\n", index, *c);
}

int main()
{
	char str[] = "Hello, world!";
	
	printf("Original string: %s\n", str);
	
	// Applying ft_striteri to print each character along with its index
	ft_striteri(str, &print_index_value);
	
	return 0;
}*/
