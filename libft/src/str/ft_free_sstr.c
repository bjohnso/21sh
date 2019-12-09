#include <stdlib.h>

void	ft_free_sstr(char **map)
{
	size_t i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
