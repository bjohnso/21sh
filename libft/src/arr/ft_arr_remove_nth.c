#include "libft.h"
#include <stddef.h>

void	ft_arr_remove_nth(int nth, void *array, size_t size, int len)
{
	unsigned char	*elem;

	if (!array || !size || !len)
		return ;
	elem = (((unsigned char *)array) + (nth * size));
	ft_memmove((void *)elem, (void *)(elem + size), (len - nth - 1) * size);
}
