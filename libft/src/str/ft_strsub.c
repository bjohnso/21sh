#include "str.h"
#include <stddef.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || (str = ft_strnew(len)) == 0)
		return (NULL);
	while (len--)
		str[i++] = s[start++];
	return (str);
}
