#include "heap.h"
#include "libft.h"
#include <stddef.h>

void	*ft_hmemalloc(size_t size)
{
	void	*ptr;

	ptr = ft_hmalloc(size);
	ft_bzero(ptr, size);
	return (ptr);
}
