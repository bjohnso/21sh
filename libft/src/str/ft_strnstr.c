#include "str.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = ft_strlen(little);
	if (size == 0)
		return ((char *)big);
	size--;
	while (big[i] != '\0' && i < (int)len)
	{
		while (big[i + j] == little[j] && i + j < (int)len)
		{
			if (j == size)
				return ((char *)(big + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
