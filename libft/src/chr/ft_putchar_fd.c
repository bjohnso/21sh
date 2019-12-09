#include <unistd.h>

int	ft_putchar_fd(int c, int fd)
{
	return ((int)write(fd, &c, 1));
}
