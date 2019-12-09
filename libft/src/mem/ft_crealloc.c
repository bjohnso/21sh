#include "mem.h"
#include "libft.h"

void	*ft_crealloc(void *ptr, int size)
{
	void	*new;

	new = ft_memalloc(size);
	ft_memcpy(new, ptr, ft_strlen(ptr));
	ft_memdel(&ptr);
	return (new);
}
