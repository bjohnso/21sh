#include <unistd.h>
#include <sys/ioctl.h>

void	ft_get_win_size(int *x, int *y)
{
	struct winsize win;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	if (x)
		*x = win.ws_col;
	if (y)
		*y = win.ws_row;
}
