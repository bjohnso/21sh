#include <unistd.h>

int	ft_putchar(int c)
{
	return ((int)write(STDOUT_FILENO, &c, 1));
}
