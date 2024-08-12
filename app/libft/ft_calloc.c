/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:32:40 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/06 12:32:42 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb != 0 && size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	dest = (void *)malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, (nmemb * size));
	return (dest);
}
/*
int main() 
{
    size_t nmemb = 5;
    size_t size = sizeof(int);

    // Allocate memory using ft_calloc
    int **array = ft_calloc(nmemb, size);

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Display the allocated memory
    printf("Allocated memory:\n");
    for (size_t i = 0; i < nmemb; i++) {
        printf("array[%zu] = %p\n", i, (void *)array[i]);
    }

    // Free the allocated memory
    for (size_t i = 0; i < nmemb; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}*/
