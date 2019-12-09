#include "libft.h"

void	ft_sstrputs(char **sstr)
{
	int i;

	if (!sstr || !*sstr)
		return ;
	i = 0;
	while (sstr[i])
	{
		ft_putendl(sstr[i]);
		i++;
	}
}
