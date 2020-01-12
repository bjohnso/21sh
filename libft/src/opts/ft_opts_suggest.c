/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_suggest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:47:22 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:47:23 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"
#include "libft.h"

int			ft_opts_suggest(t_optsdata *optsdata)
{
	ft_dprintf(STDERR_FILENO, "Try '%s --help' for more information\n",
	optsdata->prog);
	return (0);
}
