#include "ft_term_private.h"
#include <stdbool.h>

void	ft_underline(bool set)
{
	if (set == true)
		ft_termcmd("us");
	else if (set == false)
		ft_termcmd("ue");
}
