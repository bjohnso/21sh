#include <unistd.h>

int	ft_putnchar_fd(int c, int n, int fd)
{
	int	ret;
	int total;

	total = n;
	while (n-- > 0)
	{
		ret = write(fd, &c, 1);
		if (ret == -1)
			return (-1);
	}
	return (total);
}
