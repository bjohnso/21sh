/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agent_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:36:54 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/13 20:49:41 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

static char		*g_aliases[6] =
{
	"echo",
	"cd",
	"setenv",
	"unsetenv",
	"env",
	"exit"
};

char			*agent_map_target(char **env, char *alias)
{
	size_t		counter;
	int			pos;
	char		*file;

	file = NULL;
	counter = -1;
	while (++counter < ft_sstrlen((char **)g_aliases) - 1)
		if (ft_strcmp(g_aliases[counter], alias) == 0)
			return ("builtin");
	if (alias[0] == '/')
		return (alias);
	if ((pos = environ_search(env, "PATH", 4)) != -1)
		file = agent_map_target_alt(env, alias, pos);
	return (file);
}

char			*agent_map_target_alt(char **env, char *alias, int pos)
{
	char		**paths;
	char		*file;
	size_t		counter;

	file = NULL;
	paths = NULL;
	paths = ft_strsplit(env[pos] + 5, ':');
	if (paths)
	{
		counter = -1;
		while (++counter < ft_sstrlen(paths))
			if ((file = file_search(paths[counter], alias)))
				break ;
	}
	if (!file)
	{
		free(file);
		file = NULL;
	}
	if (paths)
		ft_sstrdel(&paths);
	return (file);
}

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
			if (agent->exec_args[c])
				free(agent->exec_args[c]);
		free(agent->exec_args);
	}
	if (agent->alias)
		free(agent->alias);
	if (agent->target)
		free(agent->target);
	if (agent->options)
		free(agent->options);
	free(agent);
}
