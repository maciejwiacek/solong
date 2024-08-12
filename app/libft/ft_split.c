/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:18:42 by mbaj              #+#    #+#             */
/*   Updated: 2024/03/28 14:22:43 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s_free_split(char **split)
{
	char	**str;

	str = split;
	if (!split)
		return ;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(split);
}

static size_t	s_num_subs(char const *s, char c)
{
	size_t	num_substr;
	size_t	i;

	i = 0;
	num_substr = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			num_substr++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (num_substr);
}

static char	**s_gothrou(char const *s, char c, char **result, size_t num_substr)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < num_substr)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] != c && s[len] != '\0')
			len++;
		result[i] = (char *)malloc((len + 1) * sizeof(char));
		if (result[i] == NULL)
		{
			s_free_split(result);
			return (NULL);
		}
		ft_strlcpy(result[i], s, len + 1);
		s += len;
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	num_substr;

	if (s == NULL)
		return (NULL);
	num_substr = s_num_subs(s, c);
	result = (char **)malloc((num_substr + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	s_gothrou(s, c, result, num_substr);
	result[num_substr] = NULL;
	return (result);
}
/*

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Function to print the array of strings
void print_str_array(char **arr) {
    if (arr == NULL) {
        printf("NULL\n");
        return;
    }
    printf("[ ");
    while (*arr != NULL) {
        printf("\"%s\", ", *arr);
        arr++;
    }
    printf("NULL ]\n");
}

int main(void) {
    // Test cases
    char *test_cases[] = {
        "apple,banana,cherry",
        "one,two,three",
        "a,b,c,d,e,f",
        "hello",
        "",
        NULL // End of test cases
    };

    // Test the ft_split function with each test case
    for (int i = 0; test_cases[i] != NULL; i++) {
        printf("Test case %d:\n", i + 1);
        printf("Input string: \"%s\"\n", test_cases[i]);
        printf("Delimiter: ','\n");
        char **result = ft_split(test_cases[i], 'r');
        printf("Result: ");
        print_str_array(result);
        // Free the memory allocated for the result
        char **ptr = result;
        while (*ptr != NULL) {
            free(*ptr);
            ptr++;
        }
        free(result);
        printf("\n");
    }

    return 0;
}*/
