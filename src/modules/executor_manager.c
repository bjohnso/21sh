/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:40 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 15:58:51 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ft_sh.h"

int			execute(t_shell *shell, t_agent *agent)
{
	pid_t	pid;
	int		status;

	status = 0;
	if (agent->target[0] == '/')
	{
		pid = fork();
		if (pid == 0)
		{
			execve(agent->target, agent->exec_args, shell->environ);
			status = -1;
			exit(0);
		}
		else
		{
			wait(0);
			if (status != -1)
				agent->execution_status = true;
			return (status);
		}
	}
	if ((status = execute_builtin(shell, agent)) == 0)
		agent->execution_status = true;
	return (status);
}

int			execute_builtin(t_shell *shell, t_agent *agent)
{
	char	*temp;
	int		status;

	status = 0;
	if (ft_strcmp(agent->alias, "echo") == 0)
		mini_echo(shell, agent);
	else if (ft_strcmp(agent->alias, "cd") == 0)
	{
		if ((status = mini_cd(shell, agent)) == -1)
			return (status);
		if (shell->dir[1])
			free(shell->dir[1]);
		temp = shell->dir[0];
		shell->dir[0] = getcwd(NULL, 0);
		shell->dir[1] = temp;
	}
	else if (ft_strcmp(agent->alias, "env") == 0)
		mini_env(shell);
	else if (ft_strcmp(agent->alias, "setenv") == 0)
		status = mini_setenv(shell, agent);
	else if (ft_strcmp(agent->alias, "unsetenv") == 0)
		status = mini_unsetenv(shell, agent);
	else if (ft_strcmp(agent->alias, "exit") == 0)
		shell->exit = true;
	return (status);
}
