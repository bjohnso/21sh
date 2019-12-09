#include "libft.h"
#include <stdlib.h>

char	**ft_sstrpush(char **sstr, char *str)
{
	char	**ret;
	int		size;

	size = 0;
	if (sstr)
		while (sstr[size])
			size++;
	ret = (char **)ft_memalloc(sizeof(char *) * (size + 2));
	if (!ret)
		return (NULL);
	if (sstr)
		ft_memcpy(ret, sstr, sizeof(char *) * size);
	ret[size] = ft_strdup(str);
	ret[size + 1] = NULL;
	free(sstr);
	return (ret);
}
