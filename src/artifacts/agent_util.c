/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agent_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:36:54 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 15:16:01 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

void			agent_clone(t_agent *clone, t_agent *agent)
{
	clone->alias = agent->alias;
	clone->target = agent->target;
	clone->options = agent->options;
	clone->files = agent->files;
	clone->execution_status = agent->execution_status;
}
