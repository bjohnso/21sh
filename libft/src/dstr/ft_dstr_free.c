#include "dstr.h"
#include <stdlib.h>

void	ft_dstr_free(t_dstr *dstr)
{
	if (dstr->data && dstr->cap > 0)
	{
		free(dstr->data);
		dstr->data = NULL;
	}
}
