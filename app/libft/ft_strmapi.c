/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:14:46 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/28 15:45:13 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	i = 0;
	new = (char *)malloc((len_s + 1) * sizeof (char));
	if (new == NULL)
		return (NULL);
	while (i < len_s)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[len_s] = '\0';
	return (new);
}
/*
char to_upper(unsigned int index, char c)
{
    // Convert lowercase characters to uppercase
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

int main()
{
    // Input string
    char input[] = "Hello, World!";

    // Applying ft_strmapi with to_upper function
    char *result = ft_strmapi(input, &to_upper);
    if (result != NULL)
    {
        // Printing the original and modified strings
        printf("Original string: %s\n", input);
        printf("Modified string: %s\n", result);

        // Freeing the memory allocated by ft_strmapi
        free(result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
