#include "libft.h"
#include <stdlib.h>

void	ft_lstfree(void *ptr, size_t size)
{
	(void)size;
	if (ptr)
		free(ptr);
}
