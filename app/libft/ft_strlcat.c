/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:51:13 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/05 11:51:16 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	if (dst == NULL && size == 0)
		return (0);
	dest_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dest_len >= size)
		return (size + src_len);
	if (dest_len + src_len < size)
	{
		ft_memcpy(dst + dest_len, src, src_len + 1);
	}
	else
	{
		ft_memcpy(dst + dest_len, src, size - dest_len - 1);
		dst[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototyp funkcji ft_strlcat
size_t ft_strlcat(char *dst, const char *src, size_t size);

int main() {
    // Bufor docelowy z 10 'a' i znakiem NULL na końcu
    char dest[11]; // Rozmiar 10 + znak NULL
    memset(dest, 'a', sizeof(dest) - 1); // Wypełnienie 10 'a'
    dest[10] = '\0'; // Dodanie znaku NULL na końcu

    // Napis źródłowy
    const char *src = "lorem ipsum dolor sit amet";

    // Rozmiar bufora docelowego
    size_t size = 15;

    // Wywołanie funkcji ft_strlcat
    size_t result = ft_strlcat(dest, src, size);

    // Wyświetlenie zawartości bufora po wykonaniu operacji
    printf("Final buffer content: %s\n", dest);

    // Wyświetlenie zwróconego wyniku przez ft_strlcat
    printf("Result: %zu\n", result);

    return 0;
}*/
