#include "libft.h"
#include <stddef.h>

char	**ft_sstrdup(char **sstr)
{
	size_t	size;
	char	**ret;

	if (!sstr || !*sstr)
		return (NULL);
	size = 0;
	while (sstr[size])
		size++;
	ret = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	size = 0;
	while (sstr[size])
	{
		ret[size] = ft_strdup(sstr[size]);
		size++;
	}
	return (ret);
}
