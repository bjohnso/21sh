#include <stddef.h>

char	*ft_strpbrk(const char *s, const char *charset)
{
	char	*c;

	while (*s)
	{
		c = (char *)charset;
		while (*c)
		{
			if (*c == *s)
				return ((char *)s);
			c++;
		}
		s++;
	}
	return (NULL);
}
