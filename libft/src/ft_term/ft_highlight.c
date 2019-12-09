#include "ft_term_private.h"
#include <stdbool.h>

void	ft_highlight(bool set)
{
	if (set == true)
		ft_termcmd("so");
	else if (set == false)
		ft_termcmd("se");
}
