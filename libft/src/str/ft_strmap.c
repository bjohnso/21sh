#include "str.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || (str = ft_strnew(ft_strlen(s))) == 0)
		return (0);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
