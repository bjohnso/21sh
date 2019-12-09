#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_usage(char const *name, char const *str)
{
	ft_dprintf(STDERR_FILENO, "%{bred}usage: %s%s%{eoc}\n", name, str);
	exit(EXIT_FAILURE);
}
