#include "opts.h"
#include <stddef.h>

t_opt	*ft_opts_getshort(t_opt opt_map[], char c)
{
	int	i;

	i = 0;
	while (opt_map[i].c)
	{
		if (opt_map[i].c == c)
			return (&opt_map[i]);
		i++;
	}
	return (NULL);
}
