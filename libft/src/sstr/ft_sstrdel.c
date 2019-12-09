#include "str.h"
#include <stdlib.h>

void	ft_sstrdel(char ***sstr)
{
	size_t i;

	if (!sstr)
		return ;
	i = 0;
	while ((*sstr)[i])
	{
		ft_strdel((*sstr) + i);
		i++;
	}
	ft_strdel((*sstr) + i);
	free(*sstr);
	*sstr = NULL;
}
