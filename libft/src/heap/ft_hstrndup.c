#include "heap.h"
#include <stddef.h>

char		*ft_hstrndup(char *hstr, size_t size)
{
	char	*ret;
	size_t	i;

	if (!hstr)
		return (NULL);
	ret = (char*)ft_hmalloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = -1;
	while (++i < size)
		ret[i] = hstr[i];
	return (ret);
}
