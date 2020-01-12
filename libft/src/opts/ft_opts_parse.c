/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:47:24 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:47:25 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"

void	ft_opts_parse(t_optsdata *optsdata, void *data)
{
	((t_optparser *)data)->argv = optsdata->argv;
}
