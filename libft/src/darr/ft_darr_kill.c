#include "darr.h"

void		ft_darr_kill(t_darr *array)
{
	ft_darr_clear(array);
	ft_darr_destroy(array);
}
