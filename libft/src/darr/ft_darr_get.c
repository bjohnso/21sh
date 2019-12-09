#include "darr.h"
#include <stddef.h>

void		*ft_darr_get(t_darr *array, int i)
{
	if (!(i < array->size))
		return (NULL);
	return (array->content[i]);
}
