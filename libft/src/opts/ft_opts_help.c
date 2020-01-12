/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:47:27 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:47:27 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"
#include "libft.h"
#include <unistd.h>

static void	print_flag_description(t_opt *opt)
{
	if (opt->c)
		ft_printf("-%c", opt->c);
	if (opt->name)
	{
		if (opt->c)
			ft_printf(", ");
		ft_printf("--%s", opt->name);
	}
	if (opt->arg_required)
		ft_printf("=%s", opt->metavar);
	if (opt->help)
		ft_printf("\t\t%s\n", opt->help);
}

int			ft_opts_help(t_optsdata *optsdata)
{
	int i;

	ft_dprintf(STDERR_FILENO, "%s\n", optsdata->description);
	i = 0;
	while (optsdata->opt_map[i].c)
	{
		print_flag_description(&optsdata->opt_map[i]);
		i++;
	}
	ft_dprintf(STDERR_FILENO, "    --help\t\tdisplay this help and exit\n");
	ft_dprintf(STDERR_FILENO, "%s\n", optsdata->epilog);
	return (1);
}
