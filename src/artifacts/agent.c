/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agent.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:10 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/14 15:49:26 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

t_agent			*new_agent(t_shell *shell, t_token *token)
{
	t_agent		*agent;

	agent = (t_agent *)malloc(sizeof(t_agent));
	agent->alias = ft_strdup(token->lexeme);
	agent->options = NULL;
	agent->files = NULL;
	agent->exec_args = NULL;
	agent->execution_status = false;
	if (ft_strcmp(token->type, "command") == 0)
	{
		agent->command_status = true;
		if ((agent->target = agent_map_target(shell->environ, agent->alias)))
			return (agent);
	}
	else if (ft_strcmp(token->type, "file") == 0)
	{
		agent->command_status = false;
		if ((agent->target = file_search(shell->dir[0], agent->alias)))
			return (agent);
	}
	agent_destroy(agent);
	return (NULL);
}

t_agent			*agent_opt_push(t_agent *agent, char option)
{
	size_t		len;
	size_t		counter;
	char		*temp;

	if (agent->options == NULL)
	{
		agent->options = (char *)malloc(sizeof(char) + 1);
		agent->options[0] = option;
		agent->options[1] = '\0';
	}
	else
	{
		len = ft_strlen(agent->options);
		counter = -1;
		temp = (char *)malloc(sizeof(char) * (len + 2));
		while (++counter < len)
			temp[counter] = agent->options[counter];
		temp[len] = option;
		temp[len + 1] = '\0';
		free(agent->options);
		agent->options = temp;
	}
	return (agent);
}

t_agent			*agent_files_push(t_agent *agent, char *file)
{
	size_t		len;
	size_t		counter;
	char		**temp;

	if (agent->files == NULL)
	{
		agent->files = (char **)malloc(sizeof(char) + 1);
		agent->files[0] = ft_strdup(file);
		agent->files[1] = NULL;
	}
	else
	{
		len = ft_sstrlen(agent->files);
		counter = -1;
		temp = (char **)malloc(sizeof(char *) * (len + 2));
		while (++counter < len)
			temp[counter] = agent->files[counter];
		temp[len] = ft_strdup(file);
		temp[len + 1] = NULL;
		free(agent->files);
		agent->files = temp;
	}
	return (agent);
}

t_agent			*agent_generate_exec_args(t_agent *agent)
{
	char		**exec_args;
	size_t		len;
	size_t		counter;
	size_t		counter_alt;

	if (agent->files)
		len = ft_sstrlen(agent->files);
	else
		len = 0;
	if (ft_strcmp(agent->options, "-") && agent->options)
		counter = 2;
	else
		counter = 1;
	len += counter;
	exec_args = (char **)malloc(sizeof(char *) * (len + 1));
	exec_args[0] = ft_strdup(agent->alias);
	if (counter == 2)
		exec_args[1] = ft_strdup(agent->options);
	counter_alt = counter - 1;
	while (++counter_alt < len)
		exec_args[counter_alt] = ft_strdup(agent->files[counter_alt - counter]);
	exec_args[len] = NULL;
	agent->exec_args = exec_args;
	return (agent);
}
