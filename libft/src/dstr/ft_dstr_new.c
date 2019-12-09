#include "dstr.h"
#include "libft.h"
#include <stddef.h>

int		ft_dstr_new(t_dstr *dstr, size_t init_cap)
{
	if (!dstr || !init_cap)
		return (-1);
	dstr->len = 0;
	dstr->cap = init_cap;
	if ((dstr->data = ft_memalloc(sizeof(char) * dstr->cap)) == NULL)
		return (-1);
	return (0);
}
