#include "heap.h"
#include "libft.h"
#include <stddef.h>

t_heap_man	*ft_heap_singleton(void)
{
	static t_heap_man	*heap_man;

	if (heap_man == NULL)
		heap_man = ft_memalloc(sizeof(t_heap_man));
	return (heap_man);
}
