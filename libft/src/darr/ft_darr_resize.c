#include "darr.h"
#include "libft.h"
#include <stddef.h>

int	ft_darr_resize(t_darr *array, size_t newsize)
{
	void *contents;

	if (newsize <= 0)
		return (-1);
	contents = ft_realloc(array->content, array->size * sizeof(void *),
							newsize * sizeof(void *));
	array->size = newsize;
	array->content = contents;
	return (0);
}
