#include <stddef.h>

size_t	ft_strlenchr(char *str, char c)
{
	size_t i;

	i = 0;
	while (*str && *(str++) != c)
	{
		i++;
	}
	return (i);
}
