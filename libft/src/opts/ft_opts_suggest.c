#include "opts.h"
#include "libft.h"

int			ft_opts_suggest(t_optsdata *optsdata)
{
	ft_dprintf(STDERR_FILENO, "Try '%s --help' for more information\n",
	optsdata->prog);
	return (0);
}
