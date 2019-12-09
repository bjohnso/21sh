#include "opts.h"

void	ft_opts_parse(t_optsdata *optsdata, void *data)
{
	((t_optparser *)data)->argv = optsdata->argv;
}
