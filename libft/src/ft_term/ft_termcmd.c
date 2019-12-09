#include "libft.h"
#include <term.h>
#include <stddef.h>
#include <unistd.h>

void	ft_termcmd(char *str)
{
	if (!str || !*str)
		return ;
	ft_putstr_fd(tgetstr(str, NULL), STDERR_FILENO);
}
