#include <unistd.h>
#include <stdio.h>

int		ft_getchar(void)
{
	static char	buf[BUFSIZ];
	static char	*bufp = buf;
	static int	n = 0;

	if (n == 0)
	{
		n = read(STDIN_FILENO, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
