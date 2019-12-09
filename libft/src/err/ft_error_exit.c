#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_error_exit(const char *str)
{
	ft_dprintf(STDERR_FILENO, "%{bred}Error: %s%{eoc}\n", str);
	exit(EXIT_FAILURE);
}
