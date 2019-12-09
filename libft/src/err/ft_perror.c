#include "error.h"

char	**g_argv = NULL;

int		ft_perror(char *name)
{
	name = name ? name : g_argv[0];
	return (0);
}
