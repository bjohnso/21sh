#include <stddef.h>

size_t	ft_strlenrchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}
