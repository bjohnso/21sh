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

void			agent_destroy(t_agent *agent)
{
	size_t		c;

	c = -1;
	if (agent->files)
	{
		while (++c < ft_sstrlen(agent->files))
			if (agent->files[c]) 
				free(agent->files[c]);
		free(agent->files);
	}
	if (agent->exec_args)
	{
		c = -1;
		while (++c < ft_sstrlen(agent->exec_args))
			if(agent->exec_args[c])
				free(agent->exec_args[c]);
		free(agent->exec_args);
	}
	free(agent->alias);
	free(agent->target);
	if (agent->options)
		free(agent->options);
}
