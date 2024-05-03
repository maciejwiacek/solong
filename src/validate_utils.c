#include "../includes/so_long.h"

int	len_no_newline(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	return (len);
}