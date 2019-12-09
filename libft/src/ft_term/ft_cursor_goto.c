#include "libft.h"
#include <term.h>
#include <stddef.h>
#include <unistd.h>

void	ft_cursor_goto(int x, int y)
{
	char *str1;
	char *str2;

	if ((str1 = tgetstr("cm", NULL)) != NULL)
	{
		if ((str2 = tgoto(str1, x, y)) != NULL)
			ft_putstr_fd(str2, STDERR_FILENO);
	}
}
