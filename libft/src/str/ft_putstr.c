#include "str.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	if (s)
		write(STDOUT_FILENO, s, ft_strlen(s));
}
